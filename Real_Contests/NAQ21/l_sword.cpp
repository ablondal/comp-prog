#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;

ll deg[MAXN] = {0};
bitset<100000> sset[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges(m);
	rep(i,0,m){
		int u, v;
		cin >> u >> v;
		// cout << u << v;
		edges[i] = {u, v};
		deg[u]++;
		deg[v]++;
		sset[u][v] = 1;
		sset[v][u] = 1;
	}
	ll tot = 0;
	rep(i,0,m){
		int u = edges[i].first;
		int v = edges[i].second;
		// cout << u << " " << v << endl;
		int intersec = (sset[u] & sset[v]).count();
		ll ch3 = (deg[u]-1)*(deg[u]-2)*(deg[u]-3) / 6;
		ll ch3_i = (deg[u]-2)*(deg[u]-3)*(deg[u]-4) / 6;
		tot += intersec * ch3_i;
		tot += (deg[v]-intersec-1) * ch3;
		swap(u, v);
		ch3 = (deg[u]-1)*(deg[u]-2)*(deg[u]-3) / 6;
		ch3_i = (deg[u]-2)*(deg[u]-3)*(deg[u]-4) / 6;
		tot += intersec * ch3_i;
		tot += (deg[v]-intersec-1) * ch3;
		// cout << tot << endl;
	}
	cout << tot << endl;
}