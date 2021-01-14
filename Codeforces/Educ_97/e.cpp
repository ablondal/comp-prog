#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 5e5+7;

int a[MAXN];

int DP[MAXN];

int B[MAXN];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	rep(i,0,n) scanf("%d", a+i);
	int b;
	rep(i,0,k){scanf("%d", &b); B[b-1] = true;}
	b = -1e8;
	rep(i,0,n){
		a[i]-=i;
		if (B[i]){
			if (a[i]<b){
				printf("-1\n");
				return 0;
			}else{
				b = a[i];
			}
		}
	}
	int msiz=0;
	int l_inc = 0;
	DP[0] = -1e8;
	rep(i,0,n){
		if (a[i]<DP[0]) continue;
		int lo=0, hi=msiz+1;
		while(lo+1<hi){
			int mid = (lo+hi)/2;
			if (DP[mid]<=a[i]){
				lo=mid;
			}else{
				hi=mid;
			}
		}
		DP[hi] = a[i];
		msiz = max(msiz, hi);
		if (B[i]){
			// printf("%d\n", lo);
			l_inc += lo;
			DP[0] = DP[1] = a[i];
			msiz = 1;
		}
		// rep(j,0,msiz+1){
		// 	printf(" %d", DP[j]);
		// }
		// printf("\n");
	}
	// printf("%d\n", msiz);
	l_inc += msiz;
	printf("%d\n", n-l_inc);
}










