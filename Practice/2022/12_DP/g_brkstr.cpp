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

// int len[1007][1007] = {{0}};
int cut[1007] = {0};
ll DP[1007][1007] = {{0}};
ll mid[1007][1007] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	while(cin >> n >> m){
		rep(i,1,m+1){
			cin >> cut[i];
		}
		cut[m+1] = n;
		rep(i,0,m+1){
			DP[i][i+1] = 0;
			mid[i][i+1] = i;
		}
		rep(s, 2, m+2){
			rep(i, 0, m+2){
				if (i+s > m+1) break;
				DP[i][i+s] = 1e18;
				rep(k,mid[i][i+s-1], mid[i+1][i+s]+1){
					if (DP[i][k] + DP[k][i+s] < DP[i][i+s]){
						mid[i][i+s] = k;
						DP[i][i+s] = DP[i][k] + DP[k][i+s];
					} 
				}
				DP[i][i+s] += cut[i+s] - cut[i];
			}
		}
		cout << DP[0][m+1] << endl;
	}
}