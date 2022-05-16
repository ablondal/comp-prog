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
	rep(T, 1, t+1){
		cout << "Case #" << T << ": ";
		int n;
		cin >> n;
		ll tot = 0;
		vi f(n+1);
		vi p(n+1);
		// vi ct(n+1);
		vi a(n+1, 0);

		rep(i,1,n+1) cin >> f[i];
		rep(i,1,n+1) cin >> p[i];

		for(int i=n; i>0; --i){
			if (f[i] > a[i]){
				tot += f[i]-a[i];
				a[i] = f[i];
			}
			if (a[p[i]] == 0) a[p[i]] = a[i];
			else a[p[i]] = min(a[p[i]], a[i]);
		}

		cout << tot << endl;

	}
}