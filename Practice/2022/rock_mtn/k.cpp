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

int n, m;
string s, t;
int Mi = 0;
// int id[2007], val[2007];
char vis[2007], isl[2007], val[2007], isg[2007] = {0};
vi adj[2007];
int M[2007];

inline int gpos(int i){ return (2*i) ^ (s[i] == 'B'); }

int match(int v){
	for(auto e : adj[v]){
		if (vis[e]) continue;
		vis[e] = true;
		if (M[e] == -1 || match(M[e])){
			M[e] = v;
			M[v] = true;
			return true;
		}
	}
	return false;
}

void dfs(int v){
	if (vis[v]) return;
	vis[v] = true;
	if ( (v & 1) && (M[v] != -1) ) {
		dfs(M[v]);
	} else {
		for(auto e:adj[v]){
			dfs(e);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> s >> t;
	rep(i,0,2*n){
		if ( (t[i/2] != '?') && (i & 1) != (t[i/2] == 'B') ^ (s[i/2] == 'B') ) continue;

		isg[i] = true;

		if (t[i/2] == '?') {
			if (s[i/2] == 'A') {
				val[i] = (i & 1) ? 'B' : 'A';
			} else {
				val[i] = (i & 1) ? 'A' : 'B';
			}
			adj[i].push_back(i^1);
		} else {
			val[i] = t[i/2];
		}
		// cout << i << " " << val[i] << endl;
	}
	rep(i,0,m){
		int u,v;
		cin >> u >> v;
		u--; v--;
		// cout << u << " " << v << endl;
		if (isg[2*u+1] && isg[2*v]){
			adj[2*u+1].push_back(2*v);
			adj[2*v].push_back(2*u+1);
		}
		swap(u, v);
		if (isg[2*u+1] && isg[2*v]){
			adj[2*u+1].push_back(2*v);
			adj[2*v].push_back(2*u+1);
		}
	}
	rep(i,0,2*n) M[i] = -1;
	rep(i,0,n){
		if (isg[2*i]) {
			memset(vis, false, 2007);
			match(2*i);
		}
	}
	// rep(i,0,n){
	// 	if (isg[2*i]){
	// 		cout << 2*i << ": ";
	// 		for(auto e : adj[2*i]){
	// 			cout << e << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// }

	string sol(n, 'X');

	// Visit nodes to get independant set
	memset(vis, false, 2007);
	rep(i,0,n) if (M[2*i] == -1) dfs(2*i);

	rep(i,0,n){
		if (isg[2*i] && vis[2*i]) {
			// cout << 2*i << endl;
			sol[i] = val[2*i];
		} else if (isg[2*i+1] && !vis[2*i+1]) {
			// cout << 2*i+1 << endl;
			sol[i] = val[2*i+1];
		}
	}
	cout << sol << endl;


}