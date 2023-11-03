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
		vi a(n);
		rep(i,0,n) cin >> a[i];
		sort(all(a));
		a.push_back(1e7);
		vi leftover;
		bool fail = false;
		ll cost = 0;
		int j = 0;
		rep(i,0,n+1){
			ll tmpcost = cost;
			bool s = false;
			if (a[j] == i) {
				j++;
				tmpcost++;
				s = true;
				while(a[j] == i) {
					tmpcost++;
					leftover.push_back(i);
					j++;
				}
			}
			cout << (fail ? -1 : tmpcost)  <<  " ";

			if (!s){
				if (leftover.empty()) {
					fail = true;
				} else {
					cost += (i - leftover.back());
					leftover.pop_back();
				}
			}

			

		}
		cout << endl;
	}
}