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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vll a(n);
	rep(i,0,n) cin >> a[i];
	vi yes(n, 1);
	ll m = -1e11;
	rep(i,0,n) {
		m = max(m, a[i]);
		if (m != a[i]) yes[i] = false;
	}
	reverse(all(yes));
	reverse(all(a));
	m = 1e11;
	rep(i,0,n) {
		m = min(m, a[i]);
		if (m != a[i]) yes[i] = false;
	}
	int tot = 0;
	rep(i,0,n){
		tot += (yes[i]);
	}
	cout << tot << endl;
}