#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
		printf("%d %d %lld\n", v, u, cap);
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

char grid[37][37];

// int adj[]

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	while(cin.peek() != EOF){
		string l;
		int n = 0;
		int m;
		while(true){
			if (!getline(cin, l)) break;
			if (sz(l) == 0) break;
			m = sz(l);
			rep(i,0,m){
				grid[n][i] = l[i];
			}
			n++;
		}
		Dinic din(37*37+7, 37*37, 37*37+1);
		rep(i,0,n){
			rep(j,0,m){
				if (grid[i][j] == 'W'){
					din.add_edge(37*37, i*37 + j, 1);
					if (i && grid[i-1][j] == 'I') {
						din.add_edge(i*37+j, (i-1)*37+j, 1);
					}
					if (j && grid[i][j-1] == 'I'){
						din.add_edge(i*37+j, i*37+j-1, 1);
					}
				}else if (grid[i][j]=='I'){
					if (i){
						if (grid[i-1][j] == 'W'){
							din.add_edge(i*37+j-37, i*37+j, 1);
						}else if(grid[i-1][j] == 'N'){
							din.add_edge(i*37+j,i*37+j-37,  1);
						}
					}
					if (j){
						if (grid[i][j-1] == 'W'){
							din.add_edge(i*37+j-1, i*37+j, 1);
						}else if(grid[i][j-1] == 'N'){
							din.add_edge(i*37+j,i*37+j-1,  1);
						}
					}
				}else{
					din.add_edge(i*37+j, 37*37+1, 1);
					if (i && grid[i-1][j] == 'I') {
						din.add_edge((i-1)*37+j, i*37+j, 1);
					}
					if (j && grid[i][j-1] == 'I'){
						din.add_edge(i*37+j-1, i*37+j, 1);
					}
				}
			}
		}
		cout << din.flow() << endl;
	}
}