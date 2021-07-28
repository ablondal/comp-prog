#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

long double DP[307][307][307];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int n;
	cin >> n;
	int num[3] = {0};
	rep(i,0,n){
		int ai;
		cin >> ai;
		num[ai-1]++;
	}
	DP[0][0][0] = 0;
	rep(i,0,num[2]+1){
		rep(j,0,n+1){
			rep(k,0,n+1){
				if (i==0 && j==0 && k==0) continue;
				int left = n - i - j - k;
				DP[i][j][k] = 0;
				if (i) DP[i][j][k] += DP[i-1][j+1][k]*i;
				if (j) DP[i][j][k] += DP[i][j-1][k+1]*j;
				if (k) DP[i][j][k] += DP[i][j][k-1]*k;
				DP[i][j][k] /= (double) n;
				DP[i][j][k] += 1;

				if (left < n)
					DP[i][j][k] = DP[i][j][k] / (1 - ((double)left / (double)n));
				// printf("%d %d %d: %lf\n", i, j, k, DP[i][j][k]);
			}
		}
	}

	printf("%0.14Lf\n", DP[num[2]][num[1]][num[0]]);
	// cout << tot << endl;
}