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
	int k; cin >> k;
	vi ans;
	set<int> l;
	rep(j,1,k+1){
		bool f = false;
		l.clear();
		int n; cin >> n;
		vi h(n), m(n+1, 0);
		rep(i,0,n) cin >> h[i];
		for(int i=n-1; i>=0; --i){
			m[i] = max(m[i+1], h[i]);
		}
		rep(i,0,n){
			if (m[i] == h[i]) continue;
			auto it = l.upper_bound(h[i]);
			if (it != l.end() && (*it) < m[i]){
				f = true;
				break;
			}
			l.insert(h[i]);
		}
		if (f) {
			ans.push_back(j);
		}
	}
	cout << sz(ans) << endl;
	for(auto a: ans){
		cout << a << endl;
	}
}