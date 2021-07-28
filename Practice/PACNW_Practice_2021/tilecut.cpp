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
        edges.clear();
        adj.clear();
        level.clear();
        ptr.clear();

        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
		// printf("%d %d %lld\n", v, u, cap);
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

short grid[37][37];
int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};

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
				grid[n][i] = l[i]=='W' ? 0 : l[i]=='I' ? 1 : 2;
                // cout << grid[n][i];
			}
            // cout << endl;
			n++;
		}
		Dinic din(1807, 1801, 1802);
		rep(i,0,n){
			rep(j,0,m){
                int e = i*m + j;
				din.add_edge(e, e+900, 1);
                if (grid[i][j]==0) din.add_edge(1801, e, 1);
                if (grid[i][j]==2) din.add_edge(e+900, 1802, 1);
                for(auto [dx, dy] : d){
                    int nx = i+dx;
                    int ny = j+dy;
                    // printf("%d %d\n", nx, ny);
                    if (nx>=0 && nx<n && ny>=0 && ny<m){
                        if (grid[i][j] == grid[nx][ny]-1){
                            din.add_edge(e+900, nx*m + ny, 1);
                        }
                    }
                }
                // if (i && (grid[i][j]==))
			}
		}
		cout << din.flow() << endl;
	}
}