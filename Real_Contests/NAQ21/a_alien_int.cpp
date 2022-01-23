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
	string a;
	cin >> a;
	ll n = 0;
	set<ll> S;
	rep(i,0,10){
		S.insert(i);
	}
	rep(i,0,sz(a)){
		S.erase(a[i]-'0');
		n *= 10;
		n += a[i]-'0';
	}
	vector<ll> s(all(S));

	if (s.empty()) {
		cout << "Impossible" << endl;
		return 0;
	}
	ll m = 1e18;
	ll ans = 0;
	ll ans2 = -1;
	rep(i,0,sz(s)){
		rep(j,0,sz(s)){
			ll tr = s[i];
			rep(i,0,17){
				if (abs(tr-n) == m && tr != ans){
					ans2 = tr;
				} else if (abs(tr-n) < m){
					ans = tr;
					m = abs(tr-n);
					ans2 = -1;
				}
				tr *= 10LL;
				tr += s[j];
			}
		}
	}
	if (ans2 != -1 && ans != ans2){
		if (ans > ans2) swap(ans, ans2);
		cout << ans << " " << ans2 << endl;
	} else {
		cout << ans << endl;
	}

}