#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef bitset<2007> BS;
#define double long double
const double PI = acos(-1);
const double eps = 1e-9;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("polygon.in","r",stdin);
	int t;
	cin >> t;
	while(t--){
		double p;
		double x;
		cin >> p >> x;
		if ( x >= (p/(4*PI)) ) {
			cout << "Khairy" << endl;
			continue;
		}
		//  else if ( x < sqrt(3) / 12.0 ) {
		// 	cout << "Khairy" << endl;
		// 	continue;
		// }

		ll lo = 2, hi = 1LL << 62;
		while(hi - lo > 1){
			ll md = lo + (hi-lo)/2;

			double hh = p / (4.0 * ((double)md) * tan(PI/md));
			if (hh <= x) lo = md;
			else hi = md;

		}
		cout << lo << endl;

	}

}