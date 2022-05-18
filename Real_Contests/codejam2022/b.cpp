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
	for(int T=1; T<=t; ++T){
		int n, p;
		cin >> n >> p;
		vector<vll> custs(n, vll(p));
		rep(i,0,n){
			rep(j,0,p) cin >> custs[i][j];
			sort(all(custs[i]));
		}
		ll ans = 0;
		ll DP[1007][2] = {{0}};

		rep(i,0,n){
			if (i==0){
				DP[0][0] = custs[0].back();
				DP[0][1] = custs[0].back() + (custs[0].back()-custs[0][0]);
			} else {
				DP[i][0] = min(
					DP[i-1][0] + abs(custs[i-1].back()-custs[i][0]) + custs[i].back()-custs[i][0],
					DP[i-1][1] + abs(custs[i-1][0]-custs[i][0]) + custs[i].back()-custs[i][0]);
				DP[i][1] = min(
					DP[i-1][0] + abs(custs[i-1].back()-custs[i].back()) + custs[i].back()-custs[i][0],
					DP[i-1][1] + abs(custs[i-1][0]-custs[i].back()) + custs[i].back()-custs[i][0]);
			}
		}
		
		cout << "Case #" << T << ": " << min(DP[n-1][0], DP[n-1][1]) << endl;
	}
}