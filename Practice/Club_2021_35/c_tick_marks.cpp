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

int check(int y, int x, vector<vi>& grid){
	int h = 0;
	while(true) {
		if (x-h >= 0 && x+h < sz(grid[0]) && y-h >= 0){
			if (grid[y-h][x-h] && grid[y-h][x+h]){
				h++;
			}else{
				break;
			}
		}else{
			break;
		}
		// h++
	}
	return h-1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vi> grid(n, vi(m, 0));
		vector<vi> good(n, vi(m, 0));
		rep(i,0,n){
			rep(j,0,m){
				char c;
				cin >> c;
				grid[i][j] = (c=='*');
				// cout << grid[i][j] << endl;
				int cc = check(i,j,grid);
				if (cc >= k){
					rep(h,0,cc+1){
						good[i-h][j-h] = good[i-h][j+h] = 1;
					}
				}
			}
		}
		bool w = true;
		rep(i,0,n) rep(j,0,m){
			if (grid[i][j]){
				if (!good[i][j]){
					w = false;
				}
			}
		}
		cout << (w ? "YES" : "NO") << endl;
	}
}