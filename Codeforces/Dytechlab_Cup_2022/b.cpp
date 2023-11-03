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

ll below(ll x){
	if (x == 0) return 0;
	ll lo=0, hi=1e9+1;
	while(hi-lo > 1){
		ll md = (lo+hi)/2;
		if (md*md > x){
			hi = md;
		} else {
			lo = md;
		}
	}

	ll res = 3 * (lo-1);

	ll y = x - (lo*lo);

	return res + (y / lo) + 1;

	// if (y == 0) res += 1;
	// else if ( (lo+1)*(lo+1) == x+1) res += 3;
	// else if ( )

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	// cout << below(0) << endl;
	while(t--){
		ll l, r;
		cin >> l >> r;
		cout << below(r) - below(l-1) << endl;
	}
}