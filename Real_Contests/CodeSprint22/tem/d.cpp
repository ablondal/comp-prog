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
	int n, t;
	cin >> n >> t;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	int lo = 1, hi = 2*t+1;
	int quart = ceil(n/4.0);
	int h = ceil(n/2.0);
	int threeq = ceil(3.0*n/4.0);
	while(hi-lo>1){
		int md = (hi+lo)/2;
		int qct = 0;
		int hct = 0;
		int tqct = 0;
		rep(i,0,n){
			if (a[i]/float(md) >= 0.9) qct++;
			if (a[i]/float(md) >= 0.8) hct++;
			if (a[i]/float(md) >= 0.7) tqct++;
		}
		if (qct >= quart && hct >= h && tqct >= threeq) {
			lo = md;
		} else {
			hi = md;
		}
	}
	if (lo == 1) {
		int qct = 0;
		int hct = 0;
		int tqct = 0;
		rep(i,0,n){
			if (a[i]/float(1) >= 0.9) qct++;
			if (a[i]/float(1) >= 0.8) hct++;
			if (a[i]/float(1) >= 0.7) tqct++;
		}
		if (qct >= quart && hct >= h && tqct >= threeq) {
			cout << 1 << endl;
		} else {
			cout << -1 << endl;
		}
	} else {
		cout << lo << endl;
	}
}