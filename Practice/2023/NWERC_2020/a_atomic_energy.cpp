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
const int MAXN = 10000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, q;
	cin >> n >> q;
	vll a(MAXN);
	rep(i,1,n+1){
		cin >> a[i];
	}
	rep(i,n+1, MAXN){
		a[i] = 1e18;
		rep(j,1,i){
			a[i] = min(a[i], a[j] + a[i-j]);
		}
		// if (i < 200)
		// 	cout << a[i] << endl;
	}
	rep(j,0,q){
		ll k;
		cin >> k;
		if (k < MAXN) cout << a[k] << endl;
		else {
			ll m = 1e18;
			ll k2 = k - (MAXN - 200);
			// cout << k2 << endl;
			rep(i,1,n+1){
				ll d = k2 / i;
				// cout << i << " " << d << endl;
				// cout << a[ (k2 % i) + (MAXN - 200)] << endl;
				m = min(m, a[ (k2 % i) + (MAXN - 200)] + a[i]*d);
			}
			cout << m << endl;
		}
	}
}