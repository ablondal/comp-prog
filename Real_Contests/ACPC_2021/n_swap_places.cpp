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

int n, m;
int UF[1007] = {0};

int find(int v) return (UF[v]==0 ? v : UF[v] = find(UF[v]));


vector<pair<int, int>> swaps;

vi adj[1007];
vi perm, iperm;
vi curr;

bool swap_dfs(int v, int t, int p){
	if (curr[v] == t) {
		return true;
	}
	for(auto e : adj[v]){
		if (e==p) continue;
		if (swap_dfs(e,t,v)) {
			swaps.push_back({curr[v], curr[e]});
			swap(curr[v], curr[e]);
			return true;
		}
	}
	return false;
}

char vis[1007] = {0};
void leaf_dfs(int v){
	if (vis[v]) return;
	vis[v] = true;
	for(auto e : adj[v]){
		if (!vis[e]) {
			leaf_dfs(e);
		}
	}
	swap_dfs(v, perm[v], -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i,0,m){
		int u, v;
		cin >> u >> v;
		if (find(u) != find(v)){
			int a = find(u);
			int b = find(v);
			UF[a] = b;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	perm.resize(n+1);
	iperm.resize(n+1);
	curr.resize(n+1);
	rep(i,1,n+1){
		int a;
		cin >> a;
		curr[i] = i;
		perm[i] = a;
		iperm[a] = i;
	}

	bool works = true;
	rep(i,1,n+1){
		if (find(i) != find(perm[i])) {
			works = false;
		}
	}
	if (works == false){
		cout << "impossible" << endl;
	} else {
		rep(i,1,n+1){
			leaf_dfs(i);
		}
		cout << sz(swaps) << endl;
		rep(i,0,sz(swaps)){
			cout << swaps[i].first << " " << swaps[i].second << endl;
		}
	}

}