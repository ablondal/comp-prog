#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;
const int MX = 207;
const int inf = 1e7;

vi adj[MX];
int pre[MX] = {0};
int post[MX] = {0};
int cap[MX][MX] = {{0}};
int s, t;
char vis[MX];

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() {return max(oc-c, 0LL);}
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n): lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap=0){
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a])-1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f){
		if (v==t || !f) return f;
		for(int& i = ptr[v]; i < sz(adj[v]); i++){
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					cap[v][e.to] -= p;
					cap[e.to][v] += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do {
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while(qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30-L))
						q[qe++] = e.to, lvl[e.to] = lvl[v]+1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;

		} while(lvl[t]);
		return flow;
	}
};

// int flow(int v, int t, int cc){
// 	if (v == t) return cc;
// 	for(auto& e: adj[v]){
// 		if (cap[v][e] == 0) continue;
// 		if (vis[e] && e!=t) continue;
// 		vis[e] = true;
// 		int f = flow(e, t, min(cc, cap[v][e]));
// 		if (f) {
// 			cap[v][e] -= f;
// 			cap[e][v] += f;
// 			return f;
// 		}
// 	}
// 	return 0;
// }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream in("cooling.in");
	ofstream out("cooling.out");
	int n, m;
	in >> n >> m;
	s = 0; t = n + 1;
	int totdem = 0;
	vector<pair<pair<int, int>, int>> pipes;
	Dinic D(n+2);

	rep(k,0,m){
		int i,j,l,c;
		in >> i >> j >> l >> c;
		pipes.push_back({{i,j}, l});
		totdem += l;
		pre[i] += l;
		post[j] += l;
		D.addEdge(i, j, c-l);
		// cap[i][j] += c-l;
		// adj[i].push_back(j);
		// adj[j].push_back(i);
		// cap[s][j] += l;
		// adj[s].push_back(j);
		// cap[i][t] += l;
		// adj[i].push_back(t);
	}
	rep(i,1,n+1){
		D.addEdge(s, i, post[i]);
		D.addEdge(i, t, pre[i]);
	}

	// int f, totf = 0;
	// while(true){
	// 	memset(vis, 0, MX);
	// 	int e = 0;
	// 	while(true){
	// 		f = flow(s, t, inf);
	// 		e += f;
	// 		if (!f) break;
	// 	}
	// 	if (e) {
	// 		totf += e;
	// 	} else {
	// 		break;
	// 	}
	// }
	// cout << totf << endl;

	int totf = D.calc(s, t);

	if (totf == totdem){
		out << "YES" << endl;
		for(auto &p : pipes){
			out << cap[p.first.second][p.first.first] + p.second << endl;
		}
	} else {
		out << "NO" << endl;
	}






}