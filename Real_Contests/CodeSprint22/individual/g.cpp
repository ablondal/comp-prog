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
const int MX = 1e5+7;

ll DP[MX][4] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vi a(m);
	rep(i,0,m) cin >> a[i];

	vi gaps(m-1);
	rep(i,1,m){
		gaps[i-1] = (a[i] - a[i-1] - 1);
	}
	sort(all(gaps));
	reverse(all(gaps));

	rep(i,0,MX) rep(j,0,4) DP[i][j] = 0;

	DP[0][0] = 0;

	rep(i,0,sz(gaps)+1){
		rep(j,0,4){
			// cout << i << " " << j << " " << DP[i][j] << endl;
			int days = 2*i + __builtin_popcount(j);
			if (j == 0 || j == 2){
				DP[i][j | 1] = max(DP[i][j | 1], DP[i][j] + max(n-a.back()-days,0));
			}
			if (j == 0 || j == 1){
				DP[i][j | 2] = max(DP[i][j | 2], DP[i][j] + max(a[0]-1-days,0));
			}
			if (i < sz(gaps)) {
				if (gaps[i] - 2*days == 1){
					DP[i+1][j] = max(DP[i+1][j], DP[i][j] + 1);
				} else {
					DP[i+1][j] = max(DP[i+1][j], DP[i][j] + max(gaps[i]-(2*days+1), 0));
				}
			}
		}
	}
	cout << DP[sz(gaps)][3] << endl;
}