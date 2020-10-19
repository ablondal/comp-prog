#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[104][104] = {{0}};

int n, m;
char c;

// int getDP(int i, int j){
// 	if (i<0 || i>=n || j<0 || j>=m){
// 		return 0;
// 	}
// 	if (DP[i][j]!=-1) return DP[i][j];
// 	DP[i][j] = 1000;
// 	int mm = 1000;
// 	mm = min(mm, getDP(i+1, j)+1);
// 	mm = min(mm, getDP(i-1, j)+1);
// 	mm = min(mm, getDP(i, j+1)+1);
// 	mm = min(mm, getDP(i, j-1)+1);
// 	DP[i][j] = mm;
// 	return mm;
// }

int mvs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main() {
	scanf("%d %d", &n, &m);

	rep(i,0,n){
		rep(j,0,m){
			scanf(" %c", &c);
			if (c=='.'){
				DP[i+1][j+1] = 0;
			}else{
				DP[i+1][j+1] = 1000;
			}
		}
	}

	int M = 0;
	bool did = true;
	while(did){
		did = false;
		rep(i,0,n+2){
			rep(j,0,m+2){
				if (DP[i][j]==M){
					for(int k=0; k<4; ++k){
						int ni = i+mvs[k][0];
						int nj = j+mvs[k][1];
						if (ni<0 || ni>n+1 || nj<0 || nj>m+1) continue;
						DP[ni][nj] = min(DP[ni][nj], M+1);
						if (DP[ni][nj]==M+1) did=true;
					}
				}
			}
		}
		M++;
	}
	
	// rep(i,0,n){
	// 	rep(j,0,m){
	// 		int a = getDP(i, j);
	// 		M = max(M, a);
	// 	}
	// }

	int sp = (M>9 ? 2 : 1);

	rep(i,1,n+1){
		rep(j,1,m+1){
			if(DP[i][j]==0){
				rep(k,0,sp+1) printf(".");
			}else{
				rep(k,0,(DP[i][j]>9 ? 1 : sp)) printf(".");
				printf("%d", DP[i][j]);
				
			}
		}
		printf("\n");
	}
	
}

















