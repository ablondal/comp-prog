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
	ll x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if (x3 + x1 == 2*x2 && y3 + y1 == 2*y2) {
		cout << "No" << endl;
	} else if ( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) == (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) ){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}