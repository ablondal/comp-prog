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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> cols(200007);
	rep(y,0,n){
		rep(x,0,m){
			int col;
			cin >> col;
			cols[col].push_back(x);
			cols[col+100001].push_back(y);
		}
	}
	ll tot = 0;
	rep(c,0,sz(cols)){
		if (sz(cols[c]) == 0) continue;
		auto& xs = cols[c];
		sort(all(xs));
		// rep(i,0,sz(xs)){
		// 	cout << xs[i] << " ";
		// }
		// cout << endl;
		ll c_tot = 0;
		rep(i,1,sz(xs)){
			c_tot += (i * (xs[i]-xs[i-1]));
			tot += c_tot;
		}
	}
	cout << tot << endl;
}