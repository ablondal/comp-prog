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
const int maxn = 1e5+7;

int vis[maxn] = {0}, dep[maxn] = {0};
vi adj[maxn];
int M = 0;

int dfs(int v){
	vis[v] = true;
	vi ds;
	for(auto e : adj[v]){
		if (vis[e]) continue;
		ds.push_back(dfs(e)+1);
		dep[v] = max(dep[v], ds.back());
	}
	M = max(M, dep[v]);
	sort(all(ds));
	if (sz(ds)>1){
		M = max(M, ds[sz(ds)-1] + ds[sz(ds)-2]);
	}
	return dep[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, l;
	cin >> c >> l;
	rep(i,0,l){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vi ds;
	rep(i,0,c){
		if (!vis[i]){
			M = 0;
			dfs(i);
			ds.push_back(M);
		}
	}
	sort(all(ds));
	int k = sz(ds);
	M = ds[k-1];
	if (k>1){
		M = max(M, (ds[k-1]+1)/2 + (ds[k-2]+1)/2 + 1);
	}
	if (k>2){
		M = max(M, (ds[k-2]+1)/2 + (ds[k-3]+1)/2 + 2);
	}
	cout << M << endl;
}