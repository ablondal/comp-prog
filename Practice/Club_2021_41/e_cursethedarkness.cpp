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
		double x, y;
		cin >> x >> y;
		cd pt1 = {x, y};
		int n;
		cin >> n;
		bool Y = false;
		rep(i,0,n){
			cin >> x >> y;
			cd pt2 = {x, y};
			if ( norm(pt1-pt2) <= 64.0 ) {
				Y = true;
			}
		}
		cout << (Y ? "light a candle" : "curse the darkness") << endl;

	}
}