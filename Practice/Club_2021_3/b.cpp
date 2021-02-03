#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const long double pi = 3.141592653589793;

long double maxL2 = 0;
long double minL2 = 1e18;
ll x[100007], y[100007];

typedef long double ld;

// long double dist_to_seg_sq(int px, int py, int l1x, int l1y, int l2x, int l2y){
// 	const long double l2 = (l1x-l2x)*(l1x-l2x) + (l1y-l2y)*(l1y-l2y);
// 	if (l2==0) return 1e18;
// 	long double t = ( (px-l1x)*(l2x-l1x) + (py-l1y)*(l2y-l1y) )/l2;
// 	if (t>=1 || t<=0) return 1e18;
// 	// if (t<0) return 1e18;
// 	long double vx = l1x + t*(l2x-l1x);
// 	long double vy = l1y + t*(l2y-l1y);
// 	// printf("%Lf %Lf \n", vx, vy);
// 	return (vx-px)*(vx-px) + (vy-py)*(vy-py);
// }

long double dist2(int x1,int y1, int x2, int y2){
	ld A = -x1;
	ld B = -y1;
	ld C = x2-x1;
	ld D = y2-y1;

	ld dot = A*C + B*D;
	ld len_sq = C*C + D*D;
	ld param = -1;
	if (len_sq != 0)
		param = dot/len_sq;

	if (param<0 || param>1){
		return 1e18;
	}

	ld xx = x1+param*C;
	ld yy = y1+param*D;

	return (xx*xx + yy*yy);
}

int main() {
	int n;
	int px, py;
	scanf("%d%d%d", &n, &px, &py);
	// int dir = 0;
	// int isin = true;
	rep(i,0,n){
		// int x, y;
		scanf("%lld%lld", x+i, y+i);
		x[i] -= px;
		y[i] -= py;
		ll d2 = (x[i])*(x[i]) + (y[i])*(y[i]);
		maxL2 = max(maxL2, (long double)d2);
		minL2 = min(minL2, (long double)d2);
	}

	rep(i,0,n){
		int j = (i+1) % n;
		// printf("%0.15Lf\n", dist_to_seg_sq(0,0,x[i],y[i],x[j],y[j]));
		minL2 = min(minL2, dist2(x[i],y[i],x[j],y[j]));
	}
	// printf("%0.15Lf\n", minL2);
	printf("%0.18Lf\n", pi*(maxL2-minL2));
}