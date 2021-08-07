#include <bits/stdc++.h>
using namespace std;
// too slow :P
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
int t[MAXN*4][MAXN*4];
int n, m;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = max(t[vx*2][vy], t[vx*2+1][vy]);
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = max(t[vx][vy*2], t[vx][vy*2+1]);
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 1, m);
}

int max_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return max(
    	max_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)),
        max_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry)
    );
}

int max_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return max_y(vx, 1, 1, m, ly, ry);
    int tmx = (tlx + trx) / 2;
    return max(
    	max_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry),
        max_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry)
    );
}

bool is_sq(int i, int j, int sz){
	// if (sz==0) return true;
	if (sz==1) return g[i][j];
	if (sum[i+sz-1][j+sz-1] - sum[i-1][j+sz-1] - sum[i+sz-1][j-1] + sum[i-1][j-1] == sz*sz){
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d%d", &n, &m);
	rep(i,0,n){
		rep(j,0,m){
			scanf("%d", &g[i+1][j+1]);
			sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + g[i+1][j+1];
		}
	}
	for(int i = n; i>0; --i){
		for(int j = m; j>0; --j){
			if (i==n || j == m) a[i][j] = g[i][j];
			else{
				int sz = a[i+1][j+1] + 1;
				while(!is_sq(i, j, sz)){
					sz--;
				}
				a[i][j] = sz;
			}
		}
	}
	// rep(i,0,n){
	// 	rep(j,0,m){
	// 		cout << a[i+1][j+1] << " ";
	// 	}
	// 	cout << endl;
	// }

	build_x(1, 1, n);
	int t;
	scanf("%d", &t);
	// cin >> t;
	rep(i,0,t){
		int x1, x2, y1, y2;
		// cin >> x1 >> y1 >> x2 >> y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int lo = 0;
		int hi = min(x2-x1, y2-y1)+2;
		while(hi-lo>1){
			int md = (hi+lo)>>1;
			if (max_x(1, 1, n, x1, x2-md+1, y1, y2-md+1) >= md){
				lo = md;
			} else {
				hi = md;
			}
		}
		cout << lo << endl;
	}
}