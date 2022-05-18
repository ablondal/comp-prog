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

ll DP[32][8] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t != -1){

		rep(i,0,32) rep(j,0,8) DP[i][j] = 0;
		DP[0][7] = 1;
		rep(l, 1, t+1){
			// Place horizontal
			rep(i,0,8){
				DP[l][i] += DP[l-1][i ^ 7];
			}
			// Place vertical
			DP[l][3] += DP[l][0];
			DP[l][6] += DP[l][0];
			DP[l][7] += DP[l][1] + DP[l][4];
		}

		cout << DP[t][7] << endl;

		cin >> t;
	}
}