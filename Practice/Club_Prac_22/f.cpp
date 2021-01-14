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
#define minim(a,b) a = min(a,b)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[507][507] = {{0}};

char week[507][507] = {{0}};
int n_c[507][507] = {{0}};
int fi[507];
int la[507];

int main() {
	int n, m, K;
	scanf("%d%d%d", &n, &m, &K);
	rep(i,1,n+1){
		fi[i]=m;
		la[i]=-1;
		rep(j,1,m+1){
			scanf(" %c", &week[i][j]);
			week[i][j]-='0';
			
			n_c[i][j] = n_c[i][j-1] + week[i][j];
			
			if(week[i][j]){
				fi[i] = min(fi[i],j);
				la[i] = max(la[i],j);
			}
		}
	}
	rep(i,1,n+1) rep(j,0,K+1) DP[i][j] = 600*600;
	rep(i,1,n+1){
		int skips[507];
		rep(j,0,507) skips[j] = 600;
		// int ns1 = 0;
		skips[0] = la[i]-fi[i]+1;
		skips[n_c[i][m]] = 0;
		rep(j1,fi[i],la[i]+1){
			// if(week[i][j1]) ns1++;
			// int ns2 = ns1;
			rep(j2,j1,la[i]+1){
				// printf("From %d to %d: Attended %d class, out of %d\n", j1, j2, n_c[i][j2]-n_c[i][j1-1], n_c[i][m]);
				minim(skips[ n_c[i][j1-1] + n_c[i][m] - n_c[i][j2] ], j2-j1+1);
			}
		}
		// printf("%d\n", i);
		// rep(j,0,K+1){
		// 	printf(" %d", skips[j]);
		// }
		// printf("\n");
		rep(j,0,K+1){
			rep(k,0,K+1){
				// printf("%d\n", DP[i-1][j] + skips[k]);
				if (j+k <= K) DP[i][j+k] = min(DP[i][j+k], DP[i-1][j] + skips[k]);
			}
		}
		// rep(j,0,K+1){
		// 	printf(" %d", DP[i][j]);
		// }
		// printf("\n");
	}
	int mm = 5000000;
	rep(k,0,K+1){
		minim(mm, DP[n][k]);
	}
	printf("%d\n", mm);
}









