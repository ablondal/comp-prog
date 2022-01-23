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

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, t;
	while(cin >> n >> t){
		if (n==0 && t==0) break;
		rep(i,0,t){
			ll x, y;
			char op;
			cin >> x >> op >> y;
			if (op=='+'){
				cout << (x+y) % n << endl;
			} else if (op=='-'){
				cout << (x-y+n) % n << endl;
			} else if (op=='*'){
				cout << (ll)(((__int128)x * (__int128)y) % (__int128)n) << endl;
			} else {
				// cout << gcd(y,n) << endl;
				if (gcd(y, n) == 1) {
					ll a, b;
					euclid(y, n, a, b);
					a = (a+n)%n;
					cout << (ll)(((__int128)x * (__int128)a) % (__int128)n) << endl;
				} else {
					cout << -1 << endl;
				}
			}
		}
	}
}