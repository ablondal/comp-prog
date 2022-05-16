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

ll DP[3007][8007] = {{0}};
ll b[8007] = {0};

void calc_level(int lvl, int i_lo, int i_hi, int s_lo, int s_hi) {
	if (i_lo == i_hi) return;

	int i_mid = (i_lo + i_hi) / 2;

	// if (i_mid <= lvl) {
	// 	DP[lvl][i_mid] = b[i_mid+1];
	// 	calc_level(lvl, i_lo, i_mid, s_lo, min())
	// }

	int s_mid = s_hi;
	ll m = 1e18;

	rep(i, s_lo, min(i_mid+1, s_hi)){
		if (DP[lvl-1][i] + (b[i_mid+1]-b[i+1])*(i_mid-i) < m){
			s_mid = i;
			m = DP[lvl-1][i] + (b[i_mid+1]-b[i+1])*(i_mid-i);
		}
	}

	DP[lvl][i_mid] = m;
	// cout << "DP " << lvl << " " << i_mid << ": " << m << endl;

	calc_level(lvl, i_lo, i_mid, s_lo, s_mid+1);
	calc_level(lvl, i_mid+1, i_hi, s_mid, s_hi);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, g;
	cin >> n >> g;
	vector<ll> a(n);
	rep(i,0,n){
		cin >> a[i];
		b[i+1] = b[i] + a[i];
	}
	rep(i,0,n){
		DP[1][i] = b[i+1] * (i+1);
		// cout << "DP " << 1 << " " << i << ": " << DP[1][i] << endl;
	}

	rep(j,2,min(g,n)+1){
		calc_level(j, 0, n, 0, n);
	}

	cout << DP[g][n-1] << endl;
}