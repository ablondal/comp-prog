#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

double DP[3007][3007] = {{0}};

double bp(double a, int x){
	double r = 1;
	while(x){
		if (x & 1){
			r *= a;
		}
		a *= a;
		x >>= 1;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l;
	double p;
	cin >> n >> l >> p;

	DP[0][n] = 1;

	for(int i=0; i<l; ++i){
		for(int j=n; j>0; --j){
			// cout << i << " " << j << " " << DP[i][j] << endl;
			double bpj = (j > 1 ? bp(p, j) : 0);
			DP[i][j-1] += bpj * DP[i][j];
			DP[i+1][j] += DP[i][j]*(1-bpj)/ 2;
			DP[i+1][j-1] += DP[i][j]*(1-bpj)/ 2;
		}
		// cout << i << " 0 " << DP[i][0] << endl;
	}
	double sum = 0;
	rep(j,1,n+1) {
		sum += DP[l][j];
	}
	cout << setprecision(10) << sum << endl;

	
}