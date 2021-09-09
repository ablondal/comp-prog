#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> pws;

	ll a = 1;
	for(int i = 0; i<64; ++i){
		pws.push_back(to_string(a));
		a = (a<<1);
	}

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string o = to_string(n);
		int s = sz(o);
		int m = 1000;
		for(auto& pw : pws){
			int i=0;
			for(int j=0; j<s; ++j){
				if (i < sz(pw) && pw[i] == o[j]) {
					++i;
				}
			}
			m = min(m, sz(pw)+s-2*i);
			// if (m == (sz(pw)-i) + (s-i)) {
			// 	cout << pw << endl;
			// }
		}
		cout << m << endl;
	}
}