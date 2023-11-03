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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll ans = 1;
		vi a(n), b(n, 0);
		rep(i,0,n) cin >> a[i];
		rep(i,0,n){
			if (b[i]) continue;
			ll cyc = 1;
			int j = a[i]-1;
			while(j != i){
				b[j] = 1;
				cyc++;
				j = a[j]-1;
			}
			ans = lcm(ans, cyc);
		}
		cout << ans << endl;
	}
}