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

const ll MOD = 998244353;
ll pow2[300007];

// Check bipartite while colouring
// Returns true if bipartite, and ones / twos count the size of the bipartition
int dfs(int v, int c, vi &col, vector<vi> &adj, int &ones, int &twos){
	if (col[v] && c != col[v]) return false;
	if (col[v]) return true;
	col[v] = c;
	int newc = (c == 1) ? 2: 1;
	if (c == 1) ones++;
	if (c == 2) twos++;

	for(auto to: adj[v]){
		if (!dfs(to, newc, col, adj, ones, twos)) return false;
	}
	return true;
}

void solve(){
	// Get input
	int n, m;
	cin >> n >> m;
	vector<vi> adj(n+1);
	rep(i,0,m){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// Find connected components and see if they're bipartite
	vi col(n+1, 0);
	vector<pair<int, int>> comps;
	rep(i,1,n+1){
		if (col[i]) continue;
		int ones = 0, twos = 0;
		if (!dfs(i, 1, col, adj, ones, twos)) {
			cout << 0 << endl;
			return;
		}
		comps.push_back({ones, twos});
	}

	// Do calculation.
	// There are (2^a) + (2^b) ways of colouring the component
	ll ways = 1;
	for(auto [a, b]: comps){
		ways = (ways * (pow2[a] + pow2[b])) % MOD;
	}
	cout << ways << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pow2[0] = 1;
	rep(i,1,300007){
		pow2[i] = (2 * pow2[i-1]) % MOD;
	}
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}