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

cd sq[200007] = {0};
cd partsum[200007] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, k;
	cin >> n >> m >> k;
	vi a(k);
	rep(i,0,k){
		cin >> a[i];
		sq[a[i]] = 1i;
	}

	for(int i=n-1; i>=0; --i){
		if (sq[i] != 1i){
			sq[i] = partsum[i+1] - partsum[i+1+m];
			sq[i] /= (double)m;
			sq[i] += 1.0;
		}
		partsum[i] = sq[i] + partsum[i+1];
	}

	if (imag(sq[0]) == 1) cout << "-1" << endl;
	else cout << setprecision(18) << real(sq[0]) / (1 - imag(sq[0])) << endl;
}