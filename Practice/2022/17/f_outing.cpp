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
const int MX = 1007;
vi adj[MX];
int nxt[MX], spos[MX] = {0}, vis[MX] = {0};

int loopsz(int v, int d){
	if (spos[v]) return d-spos[v];
	spos[v] = d;
	return loopsz(nxt[v], d+1);
}

int dfs(int v){
	if (vis[v]) return 0;
	vis[v] = true;
	int t = 1;
	for(auto e : adj[v]) t += dfs(e);
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bitset<MX> poss, poss2;
	poss[0] = true;
	int n, k;
	cin >> n >> k;
	rep(i,1,n+1){
		cin >> nxt[i];
		adj[nxt[i]].push_back(i);
		adj[i].push_back(nxt[i]);
	}
	rep(i,1,n+1){
		if (vis[i]) continue;
		int l = loopsz(i, 1);
		int h = dfs(i);
		// cout << l << " " << h << endl;
		poss2 = poss;
		rep(i,l,h+1) poss2 |= (poss << i);
		poss = poss2;
	}
	for(auto i=k; i>=0; i--){
		if (poss[i]){
			cout << i << endl;
			break;
		}
	}

}