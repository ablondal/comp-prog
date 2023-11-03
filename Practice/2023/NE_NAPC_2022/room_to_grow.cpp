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
	vi d(n), r(n), l(n, 0), ri(n, 0);
	rep(i,0,n) cin >> d[i] >> r[i];

	// From left
	rep(i,0,n){
		l[i] = 1;
		rep(j,0,i){
			if (d[j] < d[i]-r[i] && d[i] > d[j]+r[j]) {
				l[i] = max(l[i], l[j]+1);
			}
		}
		// cout << l[i] << " ";
	}
	// cout << endl;

	// From right
	reverse(all(d)); reverse(all(r)); reverse(all(l));
	int M = 0;
	rep(i,0,n){
		ri[i] = 1;
		rep(j,0,i){
			if (d[j] < d[i]-r[i] && d[i] > d[j]+r[j]) {
				ri[i] = max(ri[i], ri[j]+1);
			}
		}
		M = max(M, ri[i] + l[i] - 1);
	}
	cout << n - M << endl;
}