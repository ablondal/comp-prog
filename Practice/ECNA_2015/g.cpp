#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// char S[3][26] = {{0}};

int S[26] = {0};

ll DP[26][8] = {{0}};

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	double a, b;
	rep(i,0,n){
		scanf("%lf %lf", &a, &b);
		S[(int)floor(a)+1] |= (1 << (int)floor(b));
	}
	DP[0][7] = 1;

	for(int i=1; i<m+1; ++i){
		for(int pm=0; pm<7; ++pm){
			// printf("%d\n", 7 ^ pm);
			if ( ( ( 7 ^ pm) & S[i]) == 0){
				DP[i][(7 ^ pm) | S[i]] += DP[i-1][pm];
			}
		}
		// Equiv
		DP[i][S[i]] += DP[i-1][7];
		
		// Singles
		// printf("%lli\n", DP[i][7]);
		DP[i][7] += 3 * DP[i][0] + 2 * (DP[i][1]+DP[i][4]) +DP[i][2]+ DP[i][3]+DP[i][5]+DP[i][6];
		DP[i][6] += 2 * DP[i][0] + DP[i][2] + DP[i][4];
		DP[i][5] += DP[i][0] + DP[i][4] + DP[i][1];
		DP[i][4] += DP[i][0];
		DP[i][3] += 2 * DP[i][0] + DP[i][1] + DP[i][2];
		DP[i][2] += DP[i][0];
		DP[i][1] += DP[i][0];

		// rep(k,0,8) printf("%lli ", DP[i][k]);
		// printf("\n");
	}
	printf("%lli\n", DP[m][7]);

}