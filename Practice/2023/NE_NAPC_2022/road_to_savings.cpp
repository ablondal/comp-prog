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

vector<pii> G[107];
vector<tuple<int, int, int>> rds;
int n, m, a, b;


void dij(int s, vector<int> &d, vector<vector<int>> &p){
	d.clear();
	d.resize(n+1, 1e9);
	p.clear();
	p.resize(n+1);
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	Q.push({0, s});
	d[s] = 0;
	while(!Q.empty()){
		auto [dd, fr] = Q.top();
		Q.pop();
		if (d[fr] < dd) continue;
		for(auto [to, dv]: G[fr]){
			if (d[fr]+dv < d[to]){
				p[to].clear();
				p[to].push_back(fr);
				d[to] = d[fr]+dv;
				Q.push({d[to], to});
			} else if (d[fr]+dv == d[to]){
				p[to].push_back(fr);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> a >> b;
	int tot = 0;
	rep(i,0,m){
		int u, v, d;
		cin >> u >> v >> d;
		G[u].push_back({v, d});
		G[v].push_back({u, d});
		rds.push_back({u,v,d});
		tot += d;
	}
	vector<int> d;
	vector<vector<int>> p;
	dij(a, d, p);

	vector<int> vis(n+1, 0);
	queue<int> Q;
	Q.push(b);
	vis[b] = true;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		for(auto x: p[v]){
			if (!vis[x]){
				Q.push(x);
				vis[x] = true;
			}
			tot -= d[v]-d[x];
		}
	}
	cout << tot << endl;

	// dij(b, d2);
	// for(auto a: d1) cout << a << endl;
	// for(auto a: d2) cout << a << endl;

	// int tot = 0;
	// for(auto [u, v, d]: rds){
	// 	if (
	// 		(d1[u]-d1[v] == d && d2[v]-d2[u] == d) ||
	// 		(d2[u]-d2[v] == d && d1[v]-d1[u] == d)
	// 	 ) {
	// 		tot -= d;
	// 	}
	// }
	// cout << tot << endl;

}