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
const int MX = 1e5+7, NX = 107;
ll DP[NX][MX] = {{0}};
ll V[MX];
ll W[MX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, w;
	cin >> n >> w;
	for(int i=1; i<=n; ++i){
		cin >> W[i] >> V[i];
		for(int j=0; j<=w; ++j){
			if (j-W[i]>=0) DP[i][j] = DP[i-1][j-W[i]] + V[i];
			DP[i][j] = max(DP[i][j], DP[i-1][j]);
		}
	}
	cout << DP[n][w] << endl;
}