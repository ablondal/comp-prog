#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define min(a,b) ((a<b)?a:b)
#define tmin(a,b) (a = ((a<b)?a:b))

struct Edge
{
    int from, to, capacity, cost;
    Edge(int a, int b, int c, int d): from(a), to(b), capacity(c), cost(d) {}
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
	// printf("Calcing shortpath\n");
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    vector<int> n_proc(n, 0);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        // printf("processing %d for the %dth time. Cost is at %d\n", u, n_proc[u], d[u]);
        
        q.pop();
        if (n_proc[u]>n) continue;
        inq[u] = false;

        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    n_proc[v]++;
                    q.push(v);
                }
            }
        }
    }
}

char grid[1007][5];

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
            // printf("at %d\n", cur);
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}
int n;

int Vin(int i, int j){
	int v = 5*j + i;
	return (v << 1) + 2;
}
int Vout(int i, int j){
	int v = 5*j + i;
	return (v << 1 | 1) + 2;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
	scanf("%d", &n);
	while(n>0){
		vector<Edge> edges;
		char dd;
		for(int i=0; i<5; ++i){
			for(int j=0; j<n; ++j){
				scanf(" %c", &dd);
				if (dd=='@') {
					dd = 0;
					edges.emplace_back(0, Vin(i, j), 1, 0);
				}else{
					dd -= '0';
				}
				edges.emplace_back(Vin(i, j), Vout(i, j), 1, dd);
				
				for(int k=0; k<4; ++k){
					int x = i+dx[k], y = j+dy[k];
					if (x>=0 && x<5 && y>=0 && y<n){
						edges.emplace_back(Vout(i, j), Vin(x, y), 1, 0);
					}
				}
			}
		}
		for(int i=0; i<5; ++i){
			edges.emplace_back(Vout(i, n-1), 1, 1, 0);
		}
		printf("%d\n", min_cost_flow(9 + n*10, edges, 3, 0, 1));


		scanf("%d", &n);
	}
}















