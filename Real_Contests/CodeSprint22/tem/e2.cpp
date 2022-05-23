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
const ll MOD = 1e9+7;
const int MX = 3007;

ll DP[MX][2*MX] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; string s;
	cin >> n >> s;
	DP[0][MX] = 1;
	rep(i,0,n){
		if (s[i] == 'A') {
			rep(j,1,2*MX-1) {
				DP[i+1][j] += 2*DP[i][j];
				DP[i+1][j-1] += DP[i][j];
				DP[i+1][j] %= MOD;
				DP[i+1][j-1] %= MOD;
			}
		} else if (s[i] == 'F'){
			rep(j,0,2*MX) {
				DP[i+1][j] += DP[i][j];
				DP[i+1][j] %= MOD;
			}
		} else {
			rep(j,1,2*MX-1){
				DP[i+1][j] += (DP[i][j] + DP[i][j-1] + DP[i][j+1]);
				DP[i+1][j] %= MOD;
			}
		}
	}
	ll sum = 0;
	rep(i,MX+1, 2*MX){
		sum = (sum + DP[n][i]) % MOD;
	}
	cout << sum << endl;
	
}