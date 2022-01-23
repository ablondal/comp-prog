#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// ax + by = gcd(a,b)
ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll B, D, x, y, a, b, c;
		cin >> B >> D;
		a = D;
		b = B;
		c = B*B;
		// ax + by = c
		// x >= 1
		// y >= 1
		ll g = euclid(a,b,x,y);
		// ax + by = g
		if (c % g != 0){
			cout << 0 << endl;
			continue;
		} else {
			// a x*(c/g) + b y*(c/g) = c

			// x = x0 + k * b/g
			// y = y0 - k * a/g
			// b /= g;
			// a /= g;
			x = x * (c/g);
			y = y * (c/g);
			ll mink, maxk;
			// cout << x << " " << y << " " << g << endl;
			if (x <= 0) {
				mink = (abs(x) / (b/g)) + 1;
				// x += (mink) * b/g;
				// y -= (k) * a/g;
			} else {
				mink = (x-1) / (b/g);
				mink *= -1;
			}

			if (y <= 0) {
				maxk = (abs(y) / (a/g)) + 1;
				maxk *= -1;
			} else {
				maxk = (y-1) / (a/g);
			}

			cout << max(0LL, maxk - mink + 1) << endl;

		}
	}
}