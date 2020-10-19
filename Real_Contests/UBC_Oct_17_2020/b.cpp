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

double DP[25][25] = {{0}};

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int r,s,x,y,w;
		scanf("%d%d%d%d%d", &r, &s, &x, &y, &w);
		double perc = (double) (s-r+1) / s;
		DP[0][0] = 1;
		DP[0][1] = 0;
		for(int i=1; i<=y; ++i){
			for(int j=0; j<=i; ++j){
				DP[i][j] = (1-perc)*DP[i-1][j];
				if (j>0) DP[i][j] += perc*DP[i-1][j-1];
			}
		}
		double S = 0;
		rep(i,0,y+1){
			if (i>=x){
				S += DP[y][i];
			}
		}
		if (w * S > 1){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
}