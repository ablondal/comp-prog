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
const ll inf = 1e18;

ll DP[1007][1007] = {{0}};
ll M[1007][1007] = {{0}};
ll S[1007] = {0};

inline ll C(int i, int j){
	return S[j+1] - S[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	while(cin >> n >> m){
		rep(i,1,m+1){
			cin >> S[i];
		}
		S[m+1] = n;
		m++;
		rep(i,0,m-1){
			M[i][i+1] = i;
			DP[i][i+1] = C(i,i+1);
		}

		rep(l, 2, m) {
			rep(i,0,m+1) {
				int j = i+l;
				if (j>=m) continue;
				DP[i][j] = inf;
				rep(k,M[i][j-1], M[i+1][j]+1){
					DP[i][j] = min(DP[i][j], DP[i][k] + DP[k+1][j]);
					if (DP[i][j] == DP[i][k] + DP[k+1][j]){
						M[i][j] = k;
					}
				}
				DP[i][j] += C(i,j);
				// cout << i << " " << j << " " << DP[i][j] << endl;
			}
		}
		cout << DP[0][m-1] << endl;
	}
	
}