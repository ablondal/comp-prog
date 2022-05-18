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
	int n;
	cin >> n;
	ll tot = 0;
	vi a(n);
	rep(i,0,n) {
		cin >> a[i];
		tot += a[i];
	}
	ll c = 0;
	vi res;
	rep(i,0,n){
		c += a[i];
		if (c == tot/3) {
			res.push_back(i);
			c = 0;
		}
	}
	if (sz(res) == 3 && c == 0){
		cout << res[0]+1 << " " << res[1]+1 << endl;
	} else {
		cout << -1 << endl;
	}

}