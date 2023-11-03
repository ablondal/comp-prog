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
const int MX = 1e6+7;
ll p = 1e9 + 7;

ll fac[MX] = {0};
ll invfac[MX] = {0};

ll binpow(ll a, ll x){
	ll r = 1;
	while(x){
		if (x & 1) r = (r*a)%p;
		a = (a*a)%p;
		x >>= 1;
	}
	return r;
}

ll inv(ll x){
	return binpow(x, p-2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0] = 1;
	rep(i,1,MX){
		fac[i] = (fac[i-1] * i) % p;
	}
	invfac[MX-1] = inv(fac[MX-1]);
	for(int i=MX-2; i>0; --i){
		invfac[i] = (invfac[i+1]*(i+1)) % p;
	}

	int n, h;
	cin >> n >> h;
	vi k(h);
	rep(i,0,h) cin >> k[i];
	invfac[0] = 1;

	ll tot = fac[n];
	ll bad = 0;
	int c = 0;
	rep(i,0,h) {
		// int nc = c + k[i];
		// ll rm = fac[c];
		// if (i != 0) {

		// }


		int nc = c + k[i];
		ll x = fac[nc];
		if (i != 0) x -= (fac[c] * fac[k[i]]);
		x = (x % p) + p;
		x = x % p;
		// x = (x * invfac[c]) % p;
		// x = (x * invfac[k[i]]) % p;

		tot -= (x * fac[n-nc]) % p;
		tot = (tot % p) + p;
		tot = tot % p;

		c = nc;
	}
	if (c == n) {
		cout << 0 << endl;
	} else {
		cout << tot << endl;
	}

	// int t;
	// cin >> t;
	// while(t--){
	// 	;
	// }
}