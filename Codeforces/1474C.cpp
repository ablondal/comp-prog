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
		int n;
		cin >> n;
		vi a(2*n);
		rep(i,0,2*n) cin >> a[i];
		sort(all(a));
		multiset<int> b(all(a));
		vector<pair<int, int>> ans;
		bool w = true;
		int x = a[2*n-1];
		b.erase(x);
		while(sz(b) > 1){
			auto it = b.end();
			it--;
			int hi = *it;
			b.erase(it);

			if (b.find(x - hi) == b.end()) {
				w = false;
				break;
			}
			ans.push_back({hi, x-hi});
			b.erase(x-hi);
			x = hi;
		}
		if (w) {
			ans.insert(ans.begin(), {a[2*n-1], *b.begin()});
			cout << "YES" << endl;
			cout << a[2*n-1] + *b.begin() << endl;
			for(auto [x, y] : ans) cout << x << " " << y << endl;
		} else {
			cout << "NO" << endl;
			for(auto [x, y] : ans) cout << x << " " << y << endl;
		}
	}
}