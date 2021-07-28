#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1007;

int g[MAXN][MAXN];
int sum[MAXN][MAXN];
int a[MAXN][MAXN];
int t[MAXN][MAXN][11][11];
int n, m;

int lg[MAXN];

void make_sparse(){


	for(int i=n; i>0; --i){
		for(int j=m; j>0; --j){
			t[i][j][0][0] = a[i][j];
			for(int jj=1; j+(1<<jj) <= m+1; ++jj){
				t[i][j][0][jj] =
					max(t[i][j][0][jj-1], t[i][j+(1<<(jj-1))][0][jj-1]);
			}
			for(int ii=1; i+(1<<ii) <= n+1; ++ii){
				t[i][j][ii][0] =
					max(t[i][j][ii-1][0], t[i+(1<<(ii-1))][j][ii-1][0]);
			}

			for(int ii=1; i+(1<<ii) <= n+1; ++ii){
				for(int jj=1; j+(1<<jj) <= m+1; ++jj){
					t[i][j][ii][jj] =
						max(t[i][j][ii][jj-1],
							t[i][j+(1<<(jj-1))][ii][jj-1]);
				}
			}
		}
	}
}

int get_max(int x1, int y1, int x2, int y2){
	int x_i = lg[x2-x1+1];
	int y_i = lg[y2-y1+1];
	// cout << x_i << " " << y_i << endl;
	return max(
		max(
			t[x1][y1][x_i][y_i],
			t[x1][y2 - (1<<y_i) + 1][x_i][y_i]
		),
		max(
			t[x2 - (1<<x_i) + 1][y1][x_i][y_i],
			t[x2 - (1<<x_i) + 1][y2 - (1<<y_i) + 1][x_i][y_i]
		)
	);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	lg[1] = 0;
	for(int i=2; i<MAXN; ++i){
		lg[i] = lg[i/2] + 1;
	}

	scanf("%d%d", &n, &m);
	rep(i,0,n){
		rep(j,0,m){
			scanf("%d", &g[i+1][j+1]);
		}
	}
	for(int i = n; i>0; --i){
		for(int j = m; j>0; --j){
			if (i==n || j == m) a[i][j] = g[i][j];
			if (g[i][j]==0) a[i][j] = 0;
			else{
				int sz = min(a[i+1][j], a[i][j+1]);
				sz += (a[i+1][j+1] >= sz);
				a[i][j] = sz;
			}
		}
	}

	// rep(i,1,n+1) rep(j,1,m+1){
	// 	cout << a[i][j] << (j==m ? '\n' : ' ');
	// }

	make_sparse();
	int t;
	scanf("%d", &t);
	rep(i,0,t){
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int lo = 0;
		int hi = min(x2-x1, y2-y1)+2;
		while(hi-lo>1){
			int md = (hi+lo)>>1;
			// cout << lo << " " << md << " " << hi << endl;
			if (get_max(x1, y1, x2-md+1, y2-md+1) >= md){
				lo = md;
			} else {
				hi = md;
			}
		}
		cout << lo << endl;
	}
}