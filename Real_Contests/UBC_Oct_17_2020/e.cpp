#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
// done
// I'm leaving in this mess so you can see what bs I tried
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// int DP[501][501][2] = {{{0}}};
// const int INF = (int)1e9;

// int getDP(int w, int h, int p){
// 	if (DP[w][h][p]) return DP[w][h][p];
// 	if (p==0 && h<2) return DP[w][h][p] = 1;
// 	if (p==1 && w<2) return DP[w][h][p] = -1;

// 	if (p==0){
// 		DP[w][h][0] = INF;
// 		rep(i,1,h){
// 			if (DP[w-i][h][1]<0 && DP[i][h][1]<0){
// 				DP[w][h][p] = -1;
// 				break;
// 			}

// 			int ec = max(DP[w-i][h][1]+DP[i][h][0], DP[w-i][h][0]+DP[i][h][1]); 
// 			DP[w][h][p] = min(DP[w][h][p], ec);
// 		}
// 	}else{
// 		DP[w][h][1] = -INF;
// 		rep(i,1,w){
// 			int ec = min(DP[w][h-i][1]+DP[w][i][0], DP[w][h-i][0]+DP[w][i][1]); 
// 			DP[w][h][p] = max(DP[w][h][p], ec);
// 		}
// 	}

// 	return DP[w][h][p];
// }

int main() {
	int t;
	scanf("%d", &t);
	// DP[1][1][0] = 1; DP[1][1][1] = -1;
	while(t--){
		int B, D;
		string P;
		cin >> B >> D >> P;
		while(B>1 && D>1){
			B/=2;
			D/=2;
		}
		if (P=="Harry"){
			if (D!=1) printf("Harry can win\n");
			else printf("Harry cannot win\n");
		}
		else{
			if (B!=1) printf("Vicky can win\n");
			else printf("Vicky cannot win\n");
		}
		// printf("%d\n", res);
	}
}




















