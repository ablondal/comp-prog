#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x, y, l, r;
	cin >> l >> r >> x >> y;
	if (y < x || y % x != 0){
		cout << 0 << endl;
		return 0;
	}
	ll tot = x*y;
	ll mid = y / x;
	int nn = 0;
	for(ll i = 1; i<=sqrt(mid); ++i){
		if (mid % i == 0){
			if ( x * i >= l && x * i <= r && y / i >= l && y / i <= r){
				if (__gcd(i, mid/i)==1){
					if (i!=mid/i) nn+=2;
					else nn++;
				}
			}
		}
	}
	cout << nn << endl;
}