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

ll bp(ll a, ll x){
	ll r = 1;
	while(x){
		if (x & 1){
			r *= a;
			r %= MOD;
		}
		a *= a;
		a %= MOD;
		x >>= 1;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	ll tot = 0;
	rep(i,0,n){
		cin >> a[i] >> b[i];
		tot += a[i] + b[i];
	}
	ll ne = 1, no = 0;
	if (tot & 1) {
		cout << 0 << endl;
	} else {
		rep(i,0,n){
			ne *= bp(2, a[i]*b[i]);
			ne %= MOD;
		}
		ne *= bp(2, MOD-2);
		ne %= MOD;
		cout << ne << endl;
	}
}