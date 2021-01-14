#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[5007][5007] = {{0}};
int c[5007];
int lo[5007];
int hi[5007];

int main() {
	rep(i,0,5007)rep(j,0,5007) DP[i][j] = (int)1e6;
	int n;
	scanf("%d", &n);
	rep(i,0,n) scanf("%d", c+i);
	rep(i,0,n) DP[i][i] = 1;
	lo[0] = 0;
	for(int i=1; i<n; ++i){
		if (c[i] == c[i-1]){
			lo[i] = lo[i-1];
		}else lo[i] = i;
	}
	hi[n-1] = n-1;
	for(int i=n-2; i>=0; --i){
		if (c[i] == c[i+1]){
			hi[i] = hi[i+1];
		}else hi[i] = i;
	}
	rep(dist, 1, n){
		rep(i,0,n-dist){
			int j = i+dist;

			int st = min(hi[i], j);
			int en = max(i, lo[j]);
			if (en<=st) DP[i][j] = 1;
			else if (c[st]==c[en]) {
				DP[i][j] = DP[st+1][en-1] + 1;
			}else{
				DP[i][j] = min(DP[st+1][j], DP[i][en-1]) + 1;
			}
			// printf("%d %d: %d\n", i, j, DP[i][j]);
		}
	}
	printf("%d\n", DP[0][n-1]-1);
}