#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll INF = 1e18;

ll a[1000];
ll s[1000];
int n;
ll DP[1000][1000];
int M[1000][1000];

ll segsum(int i, int j){
	return s[j+1] - s[i];
	// else return (s[n] - s[i] + s[j+1] + a[i] + a[j]);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	// cout << "hi?" << endl;
	while(t--){
		// int n;
		cin >> n;
		// vi a(n);
		rep(i,0,n) cin >> a[i];
		rep(i,0,n-1) a[i+n] = a[i];
		int ms = n;
		n = 2*n - 1;
		// rep(i,0,n) cout << a[i];
		// cout << endl;
		s[0] = 0;
		rep(i,1,n+1) s[i] = a[i-1] + s[i-1];
		rep(i,0,n){
			DP[i][i] = 0;
			M[i][i] = i;
			if (i==n-1) continue;
			DP[i][i+1] = segsum(i, i+1);
			M[i][i+1] = i;
			// printf("%d %d: %lld\n", i, i+1, DP[i][i+1]);
		}
		// cout << "hi2" << endl;
		// if (n != 2){ 
			// rep(i,0,n){
			// 	DP[i][(i+2)%n]
			// }
		rep(j,2,ms){
			rep(i,0,n-j){
				DP[i][i+j] = INF;
				for(int d = M[i][i+j-1]; d <= min(i+j-1, M[i+1][i+j]) ; ++d){
					// if (d==i || (d+1)%n == i+j) continue;
					if (DP[i][d] + DP[d+1][i+j] < DP[i][i+j]){
						DP[i][i+j] = DP[i][d] + DP[d+1][i+j];
						M[i][i+j] = d;
					}
				}
				DP[i][i+j] += segsum(i, i+j );
				// printf("%d %d: %lld, %lld\n", i, i+j, DP[i][i+j], segsum(i, i+j));
			}
		}
		// cout << "hi2=3" << endl;
		ll mm = INF;
		rep(i,0,ms){
			mm = min(mm, DP[i][i+ms-1]);
		}
		cout << mm << endl;
	}
}
