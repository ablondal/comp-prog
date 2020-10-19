#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll ax, ay, bx, by, tx, ty;
ll x, y;
int n;

int main() {
	scanf("%lli %lli %lli %lli %lli %lli", &ax, &ay, &bx, &by, &tx, &ty);
	scanf("%d", &n);
	long double ans = 0.0;
	int ba = -1, ba2=-1, bb=-1, bb2=-1;
	long double besta = 1e12, bestb=1e12;
	long double besta2 = 1e12, bestb2 = 1e12;
	rep(i,0,n){
		scanf("%lli %lli", &x, &y);
		long double tmp = sqrtl((tx-x)*(tx-x) + (ty-y)*(ty-y));
		long double adist = sqrtl((ax-x)*(ax-x) + (ay-y)*(ay-y));
		long double bdist = sqrtl((bx-x)*(bx-x) + (by-y)*(by-y));
		// printf("%Lf %Lf %Lf\n", tmp, adist, bdist);
		ans += 2 * tmp;
		if (adist-tmp < besta){
			besta2=besta;
			ba2=ba;
			ba=i;
			besta = adist-tmp;
		}else if (adist-tmp < besta2){
			besta2 = adist-tmp;
			ba2 = i;
		}
		if (bdist-tmp < bestb){
			bestb2=bestb;
			bb2=bb;
			bb=i;
			bestb = bdist-tmp;
		}else if (bdist-tmp < bestb2){
			bestb2 = bdist-tmp;
			bb2 = i;
		}
	}
	if (bestb > 0 && besta > 0){
		if (bestb < besta){
			ans += bestb;
		}else{
			ans += besta;
		}
	}else if(ba == bb){
		long double tmp = min(besta+0, bestb+0);
		tmp = min(tmp, besta+bestb2);
		tmp = min(tmp, bestb+besta2);
		ans += tmp;
	}else{
		ans += min(besta+0, min(bestb+0, besta+bestb));
	}
	// printf("%d %d %d %d\n", ba, ba2, bb, bb2);
	printf("%0.8Lf\n", ans);
}























