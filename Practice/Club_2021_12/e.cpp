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
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = sz(s);
		vector<ll> a(sz(s), 0), b(sz(s), 0);
		rep(i,0,sz(s)){
			if (s[i] == 'L'){
				a[i]++;
				//b[n-i-1]++;
			}
			if (s[n-i-1] == 'L') b[n-i-1]++;
			if (i){
				a[i] += a[i-1];
				b[n-i-1] += b[n-i];
			}
		}
		ll tot = 0;
		rep(i,0,n){
			if (s[i]=='O'){
				tot += (ll)a[i] * (ll)b[i];
				// printf("%lld %lld\n", a[i], b[i]);
			}
		}
		cout << tot << endl;
	}
}