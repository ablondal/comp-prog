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

// ll DP[2007][2][7];

ll DP[2007] = {0};

ll c[2007][2007] = {{0}};

int main() {
	int n, k, p;

	c[0][1] = 1;
	scanf("%d%d%d", &n, &k, &p);

	rep(i,0,2007){
		c[i][0] = c[i][i] = 1;
	}
	rep(i,2,2007){
		rep(j,1,i){
			c[i][j] = (c[i-1][j-1]+c[i-1][j]) % p;
		}
	}

	// printf("%lli\n", c[10][5]);

	DP[1] = 1;

	rep(i, 1, n){ // What we're at
		rep(j,1,k){
			DP[i+j] += DP[i]*c[i+j-1][j];
			DP[i+j] %= p;
		}
	}
	// int tot = 0;
	printf("%lli\n", DP[n]);

}



















