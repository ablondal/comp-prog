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

ll guess(int x, int y){
	cout << x << " " << y << endl;
	ll t;
	cin >> t;
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	// cout << (ll) sqrt(349e8) << endl;
	while(n){
		// Find a ball
		// int lo = 0, hi = 1e6;
		int lo = 0, hi = 1e6;
		while(hi - lo > 6){
			int md1 = lo + (int)( (hi-lo) * (1/3.0) );
			int md2 = lo + (int)( (hi-lo) * (2/3.0) );
			ll y1 = guess(0, md1);
			ll y2 = guess(0, md2);
			if (y2 < y1){
				lo = md1;
			} else {
				hi = md2;
			}
		}
		ll m = 1e18;
		ll mx = 0;
		rep(i,lo,hi+1){
			ll g = guess(0, i);
			if (g < m){
				mx = i;
				m = g;
			}
		}
		ll y = round(sqrtl(m));
		int a = guess(y, mx);
		if (a == 0) {
			n--;
		} else {
			guess(y+1, mx);
			guess(y-1, mx);
			n--;
		}
	}
}