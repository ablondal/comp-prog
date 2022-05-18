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

ll tpow(ll n){
	ll r = 1;
	ll a = 2;
	while(n){
		if (n&1){
			r *= a;
			r %= MOD;
		}
		a = (a*a)%MOD;
		n >>= 1;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	cout << tpow(n) << endl;
}