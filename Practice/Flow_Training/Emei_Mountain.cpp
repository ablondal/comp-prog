#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

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
    	// for(int i=0; i<edges.size() / 2; ++i){
    	// 	printf("edge: %d -> %d: %lli\n", edges[2*i].v, edges[2*i].u, edges[2*i].cap);
    	// }
    	// printf("We flowing from %d to %d\n", s, t);

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

struct Monkey{
	int k, a, b;
	Monkey(int k, int a, int b) : k(k), a(a), b(b) {}
};

struct Node{
	int lo, hi;
};

int main(){
	int n, m, k, a, b;
	scanf("%d", &n);
	int cas = 1;
	while(n != 0){
		scanf("%d", &m);
		vector <Monkey> monk;
		set <int> delim;
		int tot = 0;
		for(int i=0; i<n; ++i){
			scanf("%d%d%d", &k, &a, &b);
			monk.emplace_back(k, a, b);
			delim.insert(a);
			delim.insert(b);
			tot += k;
		}

		int s = n;
		int t = n+delim.size();

		Dinic dinic( t+1, s, t );

		vector<int> sects;
		for(auto dd : delim){
			sects.push_back(dd);
		}

		for(int i=1; i<sects.size(); ++i){
			// printf("Section %d from %d to %d\n", s+i, sects[i-1], sects[i]);
			dinic.add_edge(s+i, t, (sects[i]-sects[i-1])*m);
		}

		for(int i=0; i<n; ++i){
			dinic.add_edge(n, i, monk[i].k);
			for(int j=1; j<sects.size(); ++j){
				if (monk[i].a <= sects[j-1] && monk[i].b >= sects[j]){
					dinic.add_edge(i, s+j, sects[j] - sects[j-1]);
				}
			}
		}

		long long fl = dinic.flow();
		// printf("Flow: %lli\n", fl);

		if (fl == tot){
			printf("Case %d: Yes\n", cas);
			vector <int> drank(sects.size(), 0);
			vector <pii> inter;
			for(int i=0; i<n; ++i){
				inter.clear();
				for(int id: dinic.adj[i]){
					if (dinic.edges[id].flow && dinic.edges[id].u > n){
						int to = dinic.edges[id].u - n;
						int sz = sects[to]-sects[to-1];
						int f = dinic.edges[id].flow;
						// printf("%d is the flow\n", f);
						if (f == sz){
							//printf("1 (%d,%d)\n", sects[to-1], sects[to]);
							inter.push_back({sects[to-1], sects[to]});
						}else if (drank[to] + f > sz){
							int ndr = drank[to]+f;
							ndr %= sz;
							inter.push_back({sects[to-1], sects[to-1]+ndr});
							inter.push_back({sects[to-1]+drank[to], sects[to]});
							drank[to] = ndr;
						}else{
							inter.push_back({sects[to-1]+drank[to], sects[to-1]+drank[to]+f});
							drank[to] = drank[to]+f;
							drank[to] %= sz;
						}
					}
				}
				sort(inter.begin(), inter.end());
				for(int ii = inter.size()-2; ii>=0; --ii){
					if (inter[ii].second == inter[ii+1].first){
						inter[ii].second = inter[ii+1].second;
						inter.erase(inter.begin() + ii+1);
					}
				}
				printf("%li", inter.size());
				for(auto ii: inter){
					printf(" (%d,%d)", ii.first, ii.second);
				}
				printf("\n");
			}
		}else{
			printf("Case %d: No\n", cas);
		}

		cas++;
		scanf("%d", &n);
	}
}












