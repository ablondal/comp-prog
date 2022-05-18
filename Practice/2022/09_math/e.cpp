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

double DP[1007][1007] = {{0}};

ll num1s(ll a){
	ll b = 1;
	ll tot = 0;
	while(2*b < a){
		tot += b;
		b *= 10;
	}
	if (b < a){
		tot += a-b;
	}
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<ll> ls(n+1);
	vector<ll> rs(n+1);
	DP[0][0] = 1;
	rep(i,1,n+1){
		cin >> ls[i] >> rs[i];
		rs[i]++;
		double p = (long double)(num1s(rs[i]) - num1s(ls[i])) / (long double) (rs[i]-ls[i]);
		rep(j,0,n+1){
			if (j) DP[i][j] += p * DP[i-1][j-1];
			DP[i][j] += (1-p) * DP[i-1][j];
			// cout << i << " " << j << " " << DP[i][j] << endl;
		}
	}

	ll K;
	cin >> K;
	// K /= 100;
	double tot = 0;
	rep(j,0,n+1){
		if (100*j >= n*K){
			tot += DP[n][j];
		}
	}
	cout << setprecision(18) << tot << endl;

}