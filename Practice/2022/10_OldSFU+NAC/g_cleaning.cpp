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

vector<vi> G, vis, presum, vispresum;
int n, m, k;
int nvis = 0;

inline bool obstructed(int x, int y, int siz){
	if (G[x][y]) return true;
	int dx = min(x + siz-1, n+1);
	int dy = min(y + siz-1, m+1);
	int su = presum[dx][dy] - presum[x-1][dy] - presum[dx][y-1] + presum[x-1][y-1];
	return su > 0;
}

void calclean(){
	rep(i,1,n+2) rep(j,1,m+2){
		vispresum[i][j] = vis[i][j] + vispresum[i-1][j] + vispresum[i][j-1] - vispresum[i-1][j-1];
	}
}

inline bool cleaned(int x, int y, int siz){
	int lox = max(0, x-siz), loy = max(0, y-siz);
	int cl = vispresum[x][y];
	cl -= vispresum[lox][y];
	cl -= vispresum[x][loy];
	cl += vispresum[lox][loy];
	return cl > 0;
}

void dfs(int x, int y, int siz){
	if (vis[x][y] || obstructed(x, y, siz)) return;
	vis[x][y] = true;
	// cout << x << " " << y << endl;
	nvis++;
	dfs(x-1,y,siz);
	dfs(x,y-1,siz);
	dfs(x+1,y,siz);
	dfs(x,y+1,siz);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	G.resize(n+2, vi(m+2, 0));
	presum.resize(n+2, vi(m+2, 0));
	vis.resize(n+2, vi(m+2, 0));
	vispresum.resize(n+2, vi(m+2, 0));
	rep(i,0,k){
		int u,v;
		cin >> u >> v;
		G[u][v] = 1;
	}
	rep(i,0,n+2) rep(j,0,m+2){
		if (i==0 || j==0 || i==n+1 || j==m+1){
			G[i][j] = 1;
		}
		presum[i][j] = G[i][j];
		if (i) presum[i][j] += presum[i-1][j];
		if (j) presum[i][j] += presum[i][j-1];
		if (i && j) presum[i][j] -= presum[i-1][j-1];
	}

	// rep(i,1,n+1){
	// 	rep(j,1,m+1){
	// 		cout << G[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int lo = 0, hi = max(n, m)+1;
	while(hi-lo > 1){
		// cout << hi << " " << lo << endl;
		nvis = 0;
		rep(i,0,n+2) rep(j,0,m+2) vis[i][j] = vispresum[i][j] = 0;


		int md = (hi+lo)/2;
		// cout << md << endl;
		int ct = 0;
		bool tr = 0;
		rep(i,1,n+1) rep(j,1,m+1){
			if (!obstructed(i,j,md)) {
				if (!tr){
					dfs(i,j,md);
					tr = true;
					break;
				}
			}
		}
		// rep(i,1,n+1){
		// 	rep(j,1,m+1){
		// 		cout << (vis[i][j] ? "v" : G[i][j] ? "x" : ".") << " ";
		// 	}
		// 	cout << endl;
		// }

		if (tr){
			calclean();
			rep(i,1,n+1){
				rep(j,1,m+1){
					// cout << cleaned(i, j, md) << " ";
					if (G[i][j]==0 && !cleaned(i,j,md)){
						tr = false;
						// break;
					}
				}
				// cout << endl;
			}
		}

		if (tr){
			lo = md;
		} else {
			hi = md;
		}
	}
	if (lo==0) cout << "-1" << endl;
	else cout << lo << endl;
}