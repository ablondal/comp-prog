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
const ll MOD = 1e9+7;

ll DP[1 << 21] = {{0}};
int adj[22][22] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		rep(j,0,n){
			cin >> adj[i][j];
		}
	}
	DP[0] = 1;
	rep(i,0,n){
		for(int m = (1<<n)-1; m>=0; --m){
			if (!DP[m]) continue;
			rep(to, 0, n){
				if (m & (1<<to)) continue;
				if (!adj[i][to]) continue;
				DP[m | (1<<to)] += DP[m];
				DP[m | (1<<to)] %= MOD;
			}
		}
	}
	// rep(i,0,n+1){
	// 	rep(j,0,1<<n){
	// 		cout << i << " " << j << " " << DP[i][j] << endl;
	// 	}
	// }

	cout << DP[(1<<n)-1] << endl;

	// ll ans = 0;
	// rep(i,0,1<<n){
	// 	ans = (ans + DP[n][i]) % MOD;
	// }
	// cout << ans << endl;
}