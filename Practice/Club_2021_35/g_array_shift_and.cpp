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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll n, d;
		cin >> n >> d;
		vi a(n);
		rep(i,0,n) cin >> a[i];

		ll g = gcd(n, d);
		ll m = 0;
		for(ll k=0; k<g; ++k){
			ll M = 0;
			ll l0 = -1;
			for(ll i=0; i<2*n/g; ++i){
				int v = a[ (k+(i*d))%n ];
				if (v==1) M = max(M, i-l0);
				else l0 = i;
			}
			m = max(m, M);
		}
		if (m >= n/g) {
			cout << -1 << endl;
		} else {
			cout << m << endl;
		}
	}
}