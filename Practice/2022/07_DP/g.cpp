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

ll DP[3007][107][107] = {{{0}}};
ll A[100007];
ll B[107];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	rep(i,2,n+2) cin >> A[i];
	cin >> m;
	rep(i,0,m) cin >> B[i];
	sort(B, B+m);
	reverse(B, B+m);
	rep(i,2,n+2){
		rep(j,0,m+1){
			rep(k,0,m-j+1){
				DP[i][j][k] = max(
					max(
						DP[i-2][j][k] + A[i],
						(k ? DP[i-1][j][k-1] + A[i] : 0)
					), max(
						DP[i-1][j][k],
						(j ? DP[i-1][j-1][k] + B[j-1] : 0)
					)
				);
				// cout << i << " " << j << " " << k << " " << DP[i][j][k] << endl;
			}
		}
	}
	int i = n+1;
	rep(j,0,m+1){
		rep(k,0,m-j+1){
			DP[i][j][k] = max(
				max(
					((j && k) ? DP[i][j-1][k-1] + B[j-1] : 0),
					DP[i][j][k]
				), (j ? DP[i-1][j-1][k] + B[j-1] : 0)
			);
		}
	}

	ll M = 0;
	rep(j,0,m+1){
		rep(k,0,m-j+1){
			// cout << j << " " << k << " " << DP[n+1][j][k] << endl;
			M = max(M, DP[n+1][j][k]);
		}
	}
	cout << M << endl;
}