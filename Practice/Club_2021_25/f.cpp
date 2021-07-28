#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll M = 998244353;

int DFS(int v, vector<vi>& adj, vector<int>& vis, int b){
	bool is_bip = true;
	vis[v] = b+1;
	for(auto e : adj[v]){
		if (!vis[e]) is_bip &= DFS(e, adj, vis, b^1);
		else is_bip &= vis[e]!=vis[v];
	}
	return is_bip;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vi> adj(n+1);
		vi vis(n+1,0);
		rep(i,0,m){
			int a,b;
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int mod = 0;
		rep(i,1,n+1){
			if (!vis[i]){
				mod += DFS(i, adj, vis, 0);
			}
		}
		int vars = m - n + mod; 
		ll ans = 1;
		// printf("%d\n", vars);
		rep(i,0,vars) ans = (5*ans) % M;
		printf("%lld\n", ans);
	}
}