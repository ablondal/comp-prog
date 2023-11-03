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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<char>> G(n, vector<char>(m, 0));
		int h = k, v = (n * m / 2) - k;
		int x = 0, y = 0;
		
		if (n & 1){
			h -= (m / 2);
			rep(i,0,m/2){
				G[0][2*i] = G[0][2*i+1] = 'y' + (i & 1);
			}
			y++;
		} else if (m & 1){
			v -= (n / 2);
			rep(i,0,n/2){
				G[2*i][0] = G[2*i+1][0] = 'y' + (i & 1);
			}
			x++;
		}
		if ( h >= 0 && v >= 0 && h % 2 == 0 && v % 2 == 0) {
			cout << "YES" << endl;
			for(int i=y; i<n; i+=2){
				for(int j=x; j<m; j+=2){
					if (h) {
						G[i][j] = G[i][j+1] = 'a' + 2*((i+j)%11);
						G[i+1][j] = G[i+1][j+1] = 'b' + 2*((i+j)%11);
						h-=2;
					} else {
						G[i][j] = G[i+1][j] = 'a' + 2*((i+j)%11);
						G[i][j+1] = G[i+1][j+1] = 'b' + 2*((i+j)%11);
						v-=2;
					}
				}
			}
			rep(i,0,n){
				rep(j,0,m){
					cout << G[i][j];
				}
				cout << endl;
			}
		} else {
			cout << "NO" << endl;
		}

		// while(k){

		// 	k--;
		// }
	}
}