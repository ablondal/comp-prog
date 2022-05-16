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
const int NX = 400+7;

bool DP[NX][NX] = {{0}};
ll s[NX][NX] = {{0}};
ll r[NX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n) cin >> r[i];
	rep(i,0,n) rep(j,i+1,n+1) {
		if (j) s[i][j] = s[i][j-1] + r[j-1];
	}

	rep(i,0,n){
		DP[i][i+1] = true;
	}

	rep(d,2,n){
		rep(i,0,n-d+1){
			int j = i + d;
			int l = i+1, r = j-1;
			while(l<=r){
				if (DP[i][l] && DP[r][j] && (DP[l][r] || l==r) && s[i][l] == s[r][j]){
					DP[i][j] = true;
				}
				if (s[i][l] <= s[r][j]) l++;
				else r--;
			}
			// cout << i << " " << j << " " << DP[i][j] << endl;
		}
	}

	ll M = 0;

	rep(i,0,n) rep(j,i+1,n+1) {
		if (DP[i][j]) M = max(M, s[i][j]);
	}

	cout << M << endl;
}