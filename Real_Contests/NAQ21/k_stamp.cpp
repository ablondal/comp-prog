#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	vector<ll> s(m);
	rep(i,0,m){
		cin >> s[i];
	}
	unordered_set<ll> S = {0};
	ll tot = 0;
	tot = 0;
	rep(i,1,m+1){
		tot += s[m-i];
		S.insert(tot);
	}
	ll mx = tot;
	rep(i,0,n){
		ll q;
		cin >> q;
		bool w = false;
		if (S.count(q)) w = true;
		else if (q <= mx){
			ll tot = 0;
			rep(i,0,m){
				tot += s[i];
				if (S.count(q-tot)) {
					w = true;
					break;
				} else if (q-tot < 0) {
					break;
				}
			}
		}

		if (w){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}