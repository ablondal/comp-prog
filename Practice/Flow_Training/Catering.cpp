#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

struct Edge{
	int from, to, cap;
	ll cost;
	Edge(int f, int t, int c, ll co):from(f), to(t), cap(c), cost(co) {}
};

vector<vll> adj, cost, cap;

const ll INF = 1e18;

void shortest_paths(int n, int v0, vll &d, vi &p){
	d.assign(n, INF);
	d[v0] = 0;
	vector<bool> inq(n, false);
	queue<int> q;
	q.push(v0);
	p.assign(n, -1);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int v: adj[u]) {
			if (cap[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
				d[v] = d[u] + cost[u][v];
				p[v] = u;
				if (!inq[v]){
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
}

ll min_cost_flow(int N, vector<Edge> edges, int K, int s, int t){
	adj.assign(N, vll());
	cost.assign(N, vll(N, 0));
	cap.assign(N, vll(N,0));
	for(Edge e: edges){
		adj[e.from].push_back(e.to);
		adj[e.to].push_back(e.from);
		cost[e.from][e.to] = e.cost;
		cost[e.to][e.from] = -e.cost;
		cap[e.from][e.to] = e.cap;
	}

	ll flow = 0;
	ll cost = 0;
	vi p;
	vll d;
	while(flow < K){
		shortest_paths(N, s, d, p);
		if (d[t] == INF)
			break;

		// find max flow
		ll f = K - flow;
		int cur = t;
		while(cur !=s) {
			f = min(f, cap[p[cur]][cur]);
			cur = p[cur];
		}

		// apply flow
		flow += f;
		cost += f * d[t];
		cur = t;
		while(cur != s) {
			cap[p[cur]][cur] -= f;
			cap[cur][p[cur]] += f;
			cur = p[cur];
		}
	}

	if (flow < K)
		return -1;
	else
		return cost;
}

int n, k;
ll tmp;

int main(){
	scanf("%d %d", &n, &k);
	vector<Edge> edg;
	for(int j=1; j<=n; ++j){
		scanf("%lli", &tmp);
		edg.emplace_back(0, j, 1, tmp);
	}

	edg.emplace_back(0, 2*n+1, 200, 0);

	for(int i=1; i<=n; ++i){
		edg.emplace_back(i, i+n, 1, -1e12);
		edg.emplace_back(i+n, 2*n+1, 1, 0);
		for(int j=i+1; j<=n; ++j){
			scanf("%lli", &tmp);
			edg.emplace_back(i+n, j, 1, tmp);
		}
	}

	ll fl = min_cost_flow(2*n+2, edg, k, 0, 2*n+1);
	fl += n * 1e12;
	printf("%lli\n", fl);
}























