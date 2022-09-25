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
typedef vector<vi> gph;

void dfs(int v, bool col, int& ct, vi &vis, gph &adj){
	if (vis[v]) return;
	if (col) {
		ct++;
		vis[v] = 1;
	} else {
		vis[v] = -1;
	}
	for(auto e : adj[v]){
		dfs(e, !col, ct, vis, adj);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vi> adj(n+1);
		vi vis(n+1, 0);
		rep(i,0,m){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int ct = 0;
		dfs(1, 0, ct, vis, adj);
		vi ans;
		rep(i,1,n+1){
			if (ct > (n/2) && vis[i] == -1) ans.push_back(i);
			else if (ct <= (n/2) && vis[i] == 1) ans.push_back(i);
		}
		cout << sz(ans) << endl;
		for(auto a :ans) cout << a << " ";
			cout << endl;
	}
}