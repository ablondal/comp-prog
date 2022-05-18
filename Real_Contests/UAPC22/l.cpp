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
	int n, K;
	cin >> n >> K;
	vector<ll> totds, d(n);
	rep(i,0,n-1){
		cin >> d[i+1];
		d[i+1] += d[i];
	}
	rep(i,0,n){
		rep(j,i+1,n){
			totds.push_back(d[j]-d[i]);
		}
	}
	sort(all(totds));
	totds.erase(unique(all(totds)), totds.end());
	ll m = 1e18;
	rep(i,0,sz(totds)){
		ll mdist = totds[i];
		// min dist
		int lo = i, hi = sz(totds);
		while(hi != lo){
			int md = (hi+lo)/2;
			ll maxd = totds[md];
			int MM = 1;
			vi totd(n, 1);
			rep(k,1,n){
				rep(l,0,k){
					if (d[k]-d[l] >= mdist && d[k]-d[l] <= maxd) {
						totd[k] = max(totd[k], totd[l] + 1);
					}
				}
				MM = max(MM, totd[k]);
			}
			if (MM >= K){
				hi = md;
			} else {
				lo = md+1;
			}
		}
		if (lo < sz(totds)) {
			m = min(m, totds[lo] - mdist);
			// cout << totds[lo] << " " << mdist << endl;
		}
	}
	cout << m << endl;
}