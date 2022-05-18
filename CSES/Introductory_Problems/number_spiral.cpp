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
		ll y, x;
		cin >> y >> x;
		ll layer = max(x, y);
		if (layer % 2 == 1) swap(x, y);

		if (x == layer) {
			cout << ((x-1)*(x-1)) + (y) << endl;
		} else {
			cout << ((y)*(y)) - (x-1) << endl;
		}
	}
}