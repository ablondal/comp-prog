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

int n;
char gr[4][10][10] = {{{0}}};
bool sh[10][10] = {{0}};
char t;
int order[107];

char og[10][10] = {{0}};

char st[101];

int main() {
	scanf("%d", &n);
	// if (n==1){
	// 	scanf(" %c", &t);
	// 	if (t!='.'){
	// 		printf("invalid grille\n");
	// 		return 0;
	// 	}
	// 	scanf(" %c", &t);
	// 	printf("%c\n", t);
	// 	return 0;
	// }
	int c = 0;
	rep(i,0,n){
		rep(j,0,n){
			scanf(" %c", &t);
			if(t!='X'){
				// c++;
				gr[0][i][j] = 1;
				gr[3][n-j-1][i] = 1;
				gr[2][n-i-1][n-j-1] = 1;
				gr[1][j][n-i-1] = 1;
				sh[i][j] = sh[n-j-1][i] = sh[n-i-1][n-j-1] = sh[j][n-i-1] = 1;
			}
		}
	}
	scanf(" %s", st);
	bool w = true;
	rep(i,0,n) rep(j,0,n) if (sh[i][j]==0) w = false;
	if (w==false){
		printf("invalid grille\n");
		return 0;
	}
	// c=0;
	rep(g,0,4){
		rep(i,0,n){
			rep(j,0,n){
				if (gr[g][i][j]){
					// int ii, jj;
					// if(g==0) ii=i, jj=j;
					// else if(g==1) ii=j, jj=n-i-1;
					// else if(g==2) ii=n-i-1, jj=n-j-1;
					// else ii=n-j-1, jj=i;
					og[i][j] = st[c++];
					// printf("%d %d: %c\n", i, j, st[c-1]);
				}
			}
		}
	}

	rep(i,0,n) rep(j,0,n) if (og[i][j]==0) w = false;
	if (w==false){
		printf("invalid grille\n");
		return 0;
	}
	// printf("\n");
	rep(i,0,n) rep(j,0,n) printf("%c",og[i][j]);
	printf("\n");

}





















