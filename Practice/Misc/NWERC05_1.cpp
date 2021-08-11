#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<vector<ll>> mat;
const int maxn = 1e7;

ll DP[maxn][6] = {0};

mat matmul(mat& a, mat& b){
	int n = sz(a);
	mat c(n, vll(n));
	rep(i,0,n){
		rep(j,0,n){
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int t;
	// cin >> t;
	int n;
	int cas = 0;
	while(cin >> n){
		if (n==0) break;
		cas++;
		memset(DP, false, 6*sizeof(ll)*maxn);
		vi a(n);
		rep(i,0,n){
			cin >> a[i];
		}
		DP[0][0] = 1;
		int q;
		cin >> q;
		vector<ll> ps(q);
		rep(i,0,q){
			cin >> ps[i];
		}
		int nsols = 0;
		vector<ll> ans(q, 0);
		cout << "Set " << cas << endl;
		if (sz(a)==1){
			rep(i,0,q){
				cout << "no candy for you" << endl;
			}
			continue;
		}
		int ii = 0;
		while(nsols < q){
			// cout << "DP[" << ii << "]";
			// rep(i,0,n) cout << " " << DP[ii][i];
			// cout << " : " << DP[ii][5] << endl;
			rep(i,0,q){
				if (DP[ii][5] >= ps[i] && !ans[i]){
					ans[i] = ii;
					nsols++;
				}
			}
			rep(i,0,n){
				rep(j,0,i+1){
					DP[ii+a[i]][i] += DP[ii][j];
					DP[ii+a[i]][5] += DP[ii][j];
				}
				// DP[ii+a[i]][5] += DP[ii][i];
			}
			ii++;
		}
		rep(i,0,q){
			cout << ans[i] << endl;
		}
	}
}