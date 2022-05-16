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
const ll MOD = 1e9+7;

ll binpow(ll a, ll n){
	ll r = 1;
	while(n){
		if (n & 1){
			r = (r*a)%MOD;
		}
		a = (a*a)%MOD;
		n >>= 1;
	}
	return r;
}

ll fac(ll n){
	ll res = 1;
	rep(i,1,n+1){
		res = (res*i)%MOD;
	}
	return res;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	ll top = fac(2*n);
	ll bot = (fac(n) * fac(n))%MOD;
	bot *= (n+1);
	bot %= MOD;
	top *= binpow(bot, MOD-2);
	top %= MOD;
	cout << top << endl;
}



