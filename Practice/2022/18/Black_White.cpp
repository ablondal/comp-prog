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
const int MX = 1e2+7;
const ll MOD = 1e9+7;
// DP[x][y] = DP[x-1][y-1] + DP[x-1][y+1] if x <= k
// otherwise 0

// ll DP[MX][MX][MX] = {{{0}}};

// ll ch[MX][MX] = {{0}};

ll binpow(ll a, ll x = MOD-2){
	ll r = 1;
	while(x){
		if (x & 1) {
			r *= a;
			r %= MOD;
		}
		a = (a*a)%MOD;
		x >>= 1;
	}
	return r;
}

ll choose(int n, int x){
	if (x > n || x < 0) return 0;
	ll top = 1;
	ll bot = 1;
	rep(i,n-x+1, n+1){
		top = (top*i) % MOD;
	}
	rep(i,1,x+1){
		bot = (bot*i) % MOD;
	}
	return (top * binpow(bot)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// rep(i,0,MX){
	// 	ch[i][0] = ch[i][i] = 1;
	// }
	// rep(i,1,MX){
	// 	rep(j,1,i){
	// 		ch[i][j] = (ch[i-1][j] + ch[i-1][j-1]) % MOD;
	// 	}
	// }

	// DP[nm][n][k] == ch[nm][n] - ch[nm][k]

	int n, m, k;
	cin >> n >> m >> k;
	if (n > m + k) {
		cout << 0 << endl;
		exit(0);
	} else {
		int nm = n+m;
		ll r1 = choose(nm, n);
		ll r2 = choose(nm, m+k+1);
		cout << (r1 - r2 + MOD) % MOD << endl;
		// cout << (choose(nm, n) - choose(nm, (n < (nm - k)/2 ? n : n+k+1)) + MOD) % MOD << endl;
	}
	// rep(k,0,MX){
	// 	DP[0][0][k] = 1;
	// }
	// rep(nm,1,30){
	// 	rep(n,0,nm+1){
	// 		rep(k,0,30){
	// 			if (nm - 2*n > k) continue;
	// 			DP[nm][n][k] = DP[nm-1][n][k] + (n ? DP[nm-1][n-1][k] : 0);
	// 			DP[nm][n][k] %= MOD;
	// 		}
	// 	}
	// }

	// rep(k,0,2) {
	// 	cout << "k: " << k << endl;
	// 	rep(n, 0, 10) {
	// 		rep(nm, 0, 20){
	// 			cout << ch[nm][n] - DP[nm][n][k] << " " << ch[nm][ (n < (nm - k)/2 ? n : n+k+1) ] << "\t";
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }

}