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
const int MX = 2e5+7;

bool c[MX];
vi adj[MX];
ll DP[MX][4][4] = {{{0}}};

ll cnt(int v, int p){
	ll tot = 0;
	for(auto& e : adj[v]){
		if (e == p) continue;
		tot += cnt(e, v);
		rep(i,0,3) rep(j,0,3){
			rep(k,0,3) rep(l,0,3){
				if (i + k + (!c[v]) >= 3 || j + l + c[v] >= 3 ) continue;
				tot += DP[v][i][j] * DP[e][k][l];
			}
		}
		rep(i,0,3) rep(j,0,3){
			DP[v][i][j] += DP[e][i][j];
		}
	}
	if (c[v]) {
		for(int i=2; i>=0; --i) for(int j=2; j>=0; --j){
			DP[v][i][j+1] = DP[v][i][j];
		}
		DP[v][0][1] = 1;
		DP[v][0][0] = DP[v][1][0] = DP[v][2][0] = 0;
	} else {
		for(int i=2; i>=0; --i) for(int j=2; j>=0; --j){
			DP[v][i+1][j] = DP[v][i][j];
		}
		DP[v][1][0] = 1;
		DP[v][0][0] = DP[v][0][1] = DP[v][0][2] = 0;
	}
	rep(i,0,3) rep(j,0,3){
		// cout << v << i << j << " " << DP[v][i][j] << endl;
		tot += DP[v][i][j];
	}
	tot--;
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	rep(i,1,n+1){
		char a;
		cin >> a;
		c[i] = (a == 'B' ? 1 : 0);
	}
	rep(i,0,n-1){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << ( (n*(n-1)) / 2) - cnt(1, 0) << endl;

}