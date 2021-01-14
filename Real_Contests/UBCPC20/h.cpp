#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[30007][31][31] = {{{0}}};

int st[30007];
int en[30007];

int w[30007] = {0};

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	rep(i,0,n){
		int m, a;
		scanf("%d %d", &m, &a);
		st[3*i] = en[3*i+2] = 0;
		en[3*i] = m;
		st[3*i+1] = m;
		en[3*i+1] = st[3*i+2] = a;
	}
	rep(i,0,n){
		char a[3];
		scanf(" %c%c%c", a,a+1,a+2);
		rep(j,0,3) if(a[j]=='R') w[3*i+j] = 1;
	}


	rep(i,0,3*n+1) rep(j,0,k+1) rep(l,0,k+1) DP[i][j][l] = 1000000;
	DP[0][0][0] = 0;

	rep(day,0,3*n){
		if (w[day]==1){
			rep(i,0,k+1) rep(j,0,k+1) if(i!=st[day] && j!=st[day]) DP[day][i][j] = 1000000;
		
			// rep(j,0,k+1) rep(l,0,k+1) DP[day+1][j][l] = DP[day][j][l];

			rep(j,0,k+1){
				DP[day+1][j][en[day]] = min(DP[day+1][j][en[day]], DP[day][j][st[day]]+1);
				DP[day+1][en[day]][j] = min(DP[day+1][en[day]][j], DP[day][st[day]][j]+1);
			}
			DP[day+1][en[day]][en[day]] = min(DP[day+1][en[day]][en[day]], DP[day][st[day]][st[day]]+1);
			
		}else{

			// rep(i,0,k+1){
			// 	rep(j,0,k+1){
			// 		printf(" %d", DP[day][i][j]);
			// 	}
			// 	printf("\n");
			// }
			// printf("\n");

			rep(j,0,k+1) rep(l,0,k+1) DP[day+1][j][l] = DP[day][j][l];

			rep(j,0,k+1){
				DP[day+1][j][en[day]] = min(DP[day+1][j][en[day]], DP[day][j][st[day]]+1);
				DP[day+1][en[day]][j] = min(DP[day+1][en[day]][j], DP[day][st[day]][j]+1);
			}
			DP[day+1][en[day]][en[day]] = min(DP[day+1][en[day]][en[day]], DP[day][st[day]][st[day]]+1);
		}
		// rep(i,0,k+1){
		// 	rep(j,0,k+1){
		// 		printf(" %d", DP[day+1][i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
	}
	int minim = 1000000;
	rep(i,0,k+1) rep(j,0,k+1) minim = min(minim, DP[3*n][i][j]);

	printf("%d\n", minim); 

}





























