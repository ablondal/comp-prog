#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
int DP[107][5] = {{0}};

int main() {
	scanf("%d", &n);
	rep(i,1,n+1){
		rep(j,0,3){
			DP[i][j] = 500;
		}
	}
	rep(i,1,n+1){
		int a;
		scanf("%d", &a);
		DP[i][0] = min(DP[i-1][0], min(DP[i-1][1], DP[i-1][2])) + 1;
		if (a & 1){
			DP[i][1] = min(DP[i-1][0], DP[i-1][2]);
		}
		if (a & 2){
			DP[i][2] = min(DP[i-1][0], DP[i-1][1]);
		}
	}
	int ans = min(min(DP[n][0], DP[n][1]), DP[n][2]);
	printf("%d\n", ans);
}