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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi a(n);
		rep(i,0,n) cin >> a[i];
		vi b(all(a));
		sort(all(b));
		vector<pair<pair<int, int>, int>> ans;
		rep(i,0,n-1){
			int pos = find(a.begin()+i, a.end(), b[i]) - a.begin();
			if (pos != i) {
				ans.push_back({{i+1, pos+1}, pos-i});
				rotate(a.begin()+i, a.begin()+pos, a.begin()+pos+1);
			}
		}
		// for(auto cc : a){
		// 	cout << cc << " ";
		// }
		// cout << endl;
		cout << ans.size() << endl;
		for(auto& aa : ans){
			cout << aa.first.first << " " << aa.first.second << " " << aa.second << endl;
		}
	}
}