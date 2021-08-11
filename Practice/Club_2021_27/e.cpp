#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[10007][107] = {{0}};
// int p[10007] = {0};
int c[10007] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	rep(i,1,n+1) cin >> c[i];
	rep(i,0,n+3) rep(j,0,m+1) DP[i][j] = 1e8+7;
	
	rep(i,1,m){
		DP[0][i] = 0;
	}
	rep(i,1,n+2) {
		rep(j,1,min(m, i+1)) {
			DP[i][j] = min(DP[i][j], DP[i-j][m-j] + c[i]);
		}
		rep(j,1,m){
			DP[i][j] = min(DP[i][j], DP[i][j-1]);
		}
	}
	cout << DP[n+1][m-1] << endl;
}