#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll M = 1e9+7;

ll DP[2007][1007] = {{0}};

int main() {
	// cout << M << endl;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k, m;
	cin >> n >> k >> m;
	DP[0][0] = 1;

	int maxh = min(k, m/2);

	ll tot = 0;

	rep(n,0,m){
		rep(d,0,maxh+1){
			DP[n][d] %= M;
			if (d) {
				DP[n+1][d-1] += DP[n][d];
				DP[n+1][d-1] %= M;
			}
			else if (n) {
				tot += DP[n][d];
				tot %= M;
			}
			DP[n+1][d+1] += DP[n][d];
			DP[n+1][d+1] %= M;
		}
	}
	tot = (tot+DP[m][0])%M;
	cout << (tot * 2 * n) % M << endl;
}