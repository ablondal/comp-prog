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
	ll w, H;
	cin >> w >> H;
	vll h(w+2);
	h[0] = H;
	rep(i,1,w+1) cin >> h[i];
	h[w+1] = H;
	h[w+2] = H;

	bool poss = true;
	ll ctot = 0;
	ll ta = 0;
	rep(i,1,w+3){
		if (h[i] < h[i-1] && h[i] < h[i+1]){
			
		}

		ll rm = H - h[i];
		if (rm < 0) poss = false;
		// cout << rm << endl;
		// cout << ctot << " " << ta << endl;
		if (rm == 0) {
			if (2*ta != ctot) poss = false;
			ta = 0;
			ctot = 0;
		} else {
			ta += (rm / 2);
			ctot += rm;
			if ((rm % 2) && (i % 2) ) ta++;
		}
	}
	cout << (poss ? "possible" : "impossible") << endl;

}