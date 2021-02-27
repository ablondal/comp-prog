#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll INF = 1e18+1;

ll DP[1007][1007];
ll M[1007][1007];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	while(cin >> n){
		int m;
		cin >> m;
		vi b(m+2);
		rep(i,1,m+1) cin >> b[i];
		b[0] = 0;
		b[m+1] = n;
		rep(i,0,m+1){
			DP[i][i+1] = 0;
		}
		rep(i,0,m){
			DP[i][i+2] = b[i+2] - b[i];
			M[i][i+2] = i+1;
		}
		rep(l,3,m+2){
			rep(i,0,m+2-l){
				DP[i][i+l] = INF;
				rep(c,M[i][i+l-1], M[i+1][i+l]+1){
					if (DP[i][c] + DP[c][i+l] < DP[i][i+l]){
						M[i][i+l] = c;
						DP[i][i+l] = DP[i][c] + DP[c][i+l];
					}
				}
				DP[i][i+l] += b[i+l] - b[i];
				// printf("%d %d: %lld\n", i, i+l, DP[i][i+l]);
			}
		}
		printf("%lld\n", DP[0][m+1]);
	}
}