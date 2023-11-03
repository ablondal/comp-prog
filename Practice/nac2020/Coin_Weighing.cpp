#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 998244353;

// F(k) = Sum of total number of paths with weights less than k,
// with each path counting for 2^(num of non-zeros)
// F(0) = 1
// F(1) = 3^m
// F(k) = sum over number of zeros from i=0 to m:
// 2^(m-i) * (m choose i) * (k^(m-i))
// 2^(m-i) * (m choose m-i) * (k^(m-i))
// F(k) = sum from i=0 to m (2k)^i * (m choose i)
// F(k) = (2k + 1)^m

// Now, let f(k) be the total number of non-redundant paths
// F(k) = sum from i=1 to k of f(i) if i divides k
// So, by Mobius inversion:
// f(k) = sum from i=1 to k of (mu(k/i) * F(i)) if i divides k
// mu(x) = 1 if x==1
//       = 0 if x has a square prime factor
//       = (-1)^number of prime factors otherwise

ll mu(ll x){
	if (x==1) return 1;
	ll r = 1;
	for(ll i = 2; i*i <= x; ++i){
		if (x % i == 0) {
			x /= i; r *= -1;
		}
		if (x % i == 0) return 0;
	}
	return x > 1 ? -r : r;
}

ll binpow(ll a, ll x){
	ll r = 1;
	while(x){
		if (x&1){
			r = (r*a)%MOD;
		}
		a = (a*a)%MOD;
		x >>= 1;
	}
	return r;
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	ll m, k;
	// cout << mu(4) << endl;
	cin >> m >> k;
	// ll res = 0;
	// rep(k,1,K+1){
		ll res = 0;
		rep(i,1,k+1){
			if (k % i == 0){
				// cout << i << ": " << mu(k/i) << " * " << binpow(2*i+1, m) << endl;
				res += mu(k/i) * (binpow(2*i+1, m) - 1);
				res = (res + MOD) % MOD;
			}
		}
		res += 1;
		res %= MOD;
		// cout << k << ": " << res << endl;
	// }
	cout << res << endl;
}