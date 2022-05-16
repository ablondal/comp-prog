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

string s;
int g[7][7] = {{0}};
int ans = 0;
char dir[] = {'U', 'D', 'L', 'R'};
int dd[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void dfs(int x, int y, int i){
	// cout << x << " " << y << " " << i << endl;
	if (x==0 && y==6 && i==48) {
		ans++;
		// cout << ":) " << ans << endl;
		return;
	}
	int rd = -1;
	rep(d, 0, 4){
		int nx = x+dd[d][0], ny = y+dd[d][1];
		if (0 <= nx && 0 <= ny && nx < 7 && ny < 7 && g[nx][ny] != -1) {
			g[nx][ny]--;
			if (g[nx][ny] == 1 && !(nx == 0 && ny == 6)){
				if (rd == -1){
					rd = d;
				} else {
					rd = -2;
				}
			}
		}
	}
	// cout << rd << endl;
	if (rd != -2) {
		rep(d, 0, 4){
			if (s[i] == '?' || s[i] == dir[d]) {
				if (rd == -1 || rd == d) {
					int nx = x+dd[d][0], ny = y+dd[d][1];
					// cout << nx << " " << ny << endl;
					if (0 <= nx && 0 <= ny && nx < 7 && ny < 7 && g[nx][ny] != -1) {
						int l = g[nx][ny];
						g[nx][ny] = -1;
						// cout << dir[d] << endl;
						dfs(nx, ny, i+1);
						// cout << '-' << dir[d] << endl;
						g[nx][ny] = l;
					}
				}
			}
		}
	}
	rep(d, 0, 4){
		int nx = x+dd[d][0], ny = y+dd[d][1];
		if (0 <= nx && 0 <= ny && nx < 7 && ny < 7 && g[nx][ny] != -1) {
			g[nx][ny]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	rep(x,0,7) rep(y,0,7){
		if (x) g[x][y]++;
		if (y) g[x][y]++;
		if (6-x) g[x][y]++;
		if (6-y) g[x][y]++;
		// cout << g[x][y] << " ";
	}
	g[0][0] = -1;
	dfs(0, 0, 0);
	cout << ans << endl;
}