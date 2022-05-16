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

double DP[107][107];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, v1, v2;
		double w;
		cin >> n >> v1 >> v2 >> w;
		int l = n - v1 - v2;
		DP[0][0] = 1;
		rep(i,1,107){
			DP[0][i] = 0;
			DP[i][0] = DP[i-1][0] * 0.5;
		}
		// DP[0][0] = 1;
		rep(i,1,n+1){
			rep(j,1,n+1){
				DP[i][j] = 0;
				DP[i][j] += 0.5 * DP[i-1][j-1];
				DP[i][j] += 0.5 * DP[i-1][j];
			}
		}
		double tot = 0;
		rep(i,0,n+1){
			if (v1 + i > v2 + (l-i)){
				// cout << i << endl;
				tot += DP[n-v1-v2][i];
			}
		}
		// cout << tot << endl;
		if (tot < 1e-9){
			cout << "RECOUNT!" << endl;
		} else if (tot > w/100.0) {
			cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
		} else {
			cout << "PATIENCE, EVERYONE!" << endl;
		}
		// cout << (tot > w/100.0 ? )

	}
}