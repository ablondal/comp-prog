#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <set>
using namespace std;
// done, I hate this problem statement
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

set<int> delims_x, delims_y;
int h, w, n, m;

int DP[101][101] = {{0}};
vector<pii> pts;

int main() {
	scanf("%d%d%d%d", &h, &w, &n, &m);
	// int nn = 0;
	delims_y.insert(h);
	delims_x.insert(w);
	rep(i,0,n+m){
		int x, y;
		scanf("%d%d", &y, &x);
		y += 7;
		x += 4;
		pts.push_back({x,y});
		if (x>=w || y >=h) continue;
		
		delims_x.insert(x);
		delims_y.insert(y);
	}
	vi xs(all(delims_x)), ys(all(delims_y));
	rep(i,0,sz(xs)){
		rep(j,0,sz(ys)){
			rep(k,0,sz(pts)){
				if (pts[k].first < xs[i] && pts[k].second < ys[j]){
					if(k<n) DP[i][j]--;
					else DP[i][j]++;
				}
			}
		}
	}
	int minimum = 0;
	rep(i,0,sz(xs)){ rep(ii, i+1, sz(xs)){
		rep(j,0,sz(ys)){ rep(jj, j+1, sz(ys)){
			minimum = min(minimum, DP[ii][jj] + DP[i][j] - DP[ii][j] - DP[i][jj]);
		}}
	}}
	printf("%d\n", n+minimum);
}















