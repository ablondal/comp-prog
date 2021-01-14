#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[400][200] = {{0}};

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		vi t(n);
		rep(i,0,n) scanf("%d", &t[i]);
		sort(all(t));
		int M = t[n-1]+n;
		rep(i,0,M) rep(j,0,200) DP[i][j] = (int)1e7;
		rep(i,1,M){
			DP[i][0] = abs(t[0]-i);
		}
		rep(dish,1,n){
			rep(time,dish+1,M){
				rep(i,1,time){
					DP[time][dish] = min(DP[time][dish], DP[i][dish-1]+abs(t[dish]-time));
				}
			}
		}
		int mm = 1e9;
		rep(time,0,M){
			mm = min(mm, DP[time][n-1]);
		}
		// rep(i,0,n){
		// 	rep(j,1,M){
		// 		printf(" %d", DP[j][i]);
		// 	}
		// 	printf("\n");
		// }

		printf("%d\n", mm);
	}
}