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
const ll MOD = (1e9 + 7);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	rep(i,0,n) cin >> a[i];
	rep(i,0,n) cin >> b[i];
	sort(all(a));
	sort(all(b));
	ll s = 0;
	while(k) {
		if (a[n-1] == b[n-1]) {
			a[n-1] += k/2;
			b[n-1] += k/2;
			a[n-1] += (k & 1);
			a[n-1] %= MOD;
			b[n-1] %= MOD;
			k = 0;
		} else if (a[n-1] > b[n-1]) {
			ll c = min(k, a[n-1]-b[n-1]);
			b[n-1] += c;
			k -= c;
		} else if (a[n-1] < b[n-1]) {
			ll c = min(k, b[n-1]-a[n-1]);
			a[n-1] += c;
			k -= c;
		}
	}
	rep(i,0,n){
		// cout << a[i] << " " << b[i] << endl;
		s += a[i]*b[i];
		s %= MOD;
	}
	cout << s << endl;
}