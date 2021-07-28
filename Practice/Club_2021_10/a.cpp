#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll inf = 1e18;

ll DP[107][107];
ll stones[107];
int siz[107];

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin >> t;
	for(int cas = 1; cas<=t; ++cas){
		ll d;
		int n;
		cin >> n >> d;
		rep(i,0,107){
			rep(j,0,107){
				DP[i][j] = inf;
			}
		}
		rep(i,1,n+1){
			char s;
			ll dis;
			scanf(" %c-%lld", &s, &dis);
			// cout << s << " " << dis << endl;
			stones[i] = dis;
			siz[i] = (s == 'S' ? 0 : 1);
		}
		stones[0] = 0;
		siz[0] = 1;
		stones[n+1] = d;
		siz[n+1] = 1;
		DP[0][0] = 0;
		rep(sum,0,2*n+3){
			rep(i,0,min(sum+1, n+2)){
				int j = sum - i;
				if (i==j && siz[i]==0) continue;
				if (i<j){
					rep(k,max(i+1,j),n+2){
						if (k==j && siz[k]==0) continue;
						DP[k][j] = min(DP[k][j], max(DP[i][j], stones[k]-stones[i]));
					}
				}else{
					rep(k,max(j+1,i),n+2){
						if (k==i && siz[k]==0) continue;
						DP[i][k] = min(DP[i][k], max(DP[i][j], stones[k]-stones[j]));
					}
				}
				// printf("%d %d: %lld\n", i, j, DP[i][j]);
			}
		}

		ll ans = DP[n+1][n+1];
		printf("Case %d: %lld\n", cas, ans);
	}
}
/*
3
1 10
B-5
1 10
S-5
2 10
B-3 S-6

*/