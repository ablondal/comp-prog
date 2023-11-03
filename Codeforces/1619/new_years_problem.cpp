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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int m, n;
		cin >> m >> n;
		vector<vi> p(m, vi(n));
		vi max_fr(n, 0);
		int lo = 2e9, hi = -2e9;
		rep(i,0,m){
			rep(j,0,n){
				cin >> p[i][j];
				max_fr[j] = max(max_fr[j], p[i][j]);
				lo = min(lo, p[i][j]);
			}
		}
		int mm = max_fr[0];
		rep(j,0,n) mm = min(max_fr[j], mm);
		if (m < n) {
			cout << mm << endl;
			continue;
		}
		hi = mm+1;
		while(hi-lo > 1){
			int md = (hi+lo)/2;
			bool w = false;
			vi r_ct(m);
			rep(i,0,m){
				rep(j,0,n){
					if (p[i][j]>=md){
						r_ct[i]++;
					}
				}
				if (r_ct[i] > 1) w = true;
			}
			if (w) {
				lo = md;
			} else {
				hi = md;
			}
		}
		cout << lo << endl;

	}
}