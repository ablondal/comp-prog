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

vi adj[50];
char vis[50] = {0};
char v2[50];
char cut[50][50] = {{0}};
int vnum = 0;
int n;

int dfs(int v, int p){
	if (v2[v]) return 0;
	v2[v] = 1;
	for(auto e : adj[v]){
		if (e == p || cut[v][e]) continue;
		return dfs(e, v) + 1;
	}
	return 0;
}

ll tot = 0;

void count_g_cut(int i) {
	if (i == n) {
		memset(v2, 0, n);
		if (dfs(0, -1) == n) {
			tot++;
		}
	} else if (vis[i]) {
		count_g_cut(i+1);
	} else {
		for(auto e:adj[i]){
			if (vis[e]) continue;
			cut[i][e] = cut[e][i] = vis[e] = vis[i] = 1;
			count_g_cut(i+1);
			cut[i][e] = cut[e][i] = vis[e] = vis[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep (i,0,(n/2)*3) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	count_g_cut(0);
	cout << tot << endl;
	
}