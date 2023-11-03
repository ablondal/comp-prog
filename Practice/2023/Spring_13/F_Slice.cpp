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
ll M = 60 * 60 * 360;
bitset<1296000> S;
double pi = acos(-1);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m; cin >> m;
	while(m--) {
		S.reset();
		ll mun = -1;
		ll r, n, t, m, s;
		cin >> r >> n >> t >> m >> s;
		t = 3600 * t + 60 * m + s;
		auto L = M / gcd(t, M);
		if (L <= n){
			mun = gcd(t, M);
		} else {
			int c = 0;
			rep(i,0,n){
				S[c] = 1;
				c = (c + t) % M;
			}
			int i=1, j=0;
			while(i < M){
				while(i < M && !S[i]) i++;
				// cout << i << " " << j << endl;
				mun = max((ll)i-j, mun);
				j=i;
				i++;
			}
			mun = max(mun, M-j);
		}
		cout << setprecision(10) << pi*r*r*((double)mun / (double)M) << endl;
	}
	
}