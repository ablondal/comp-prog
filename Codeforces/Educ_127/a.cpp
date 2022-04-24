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
		string s;
		cin >> s;
		vector<bool> canb(sz(s)+1, 0);
		canb[0] = true;
		rep(i,2,sz(s)+1){
			if (s[i-1] == s[i-2]){
				if (canb[i-2]) canb[i] = true;
				else if (i >= 3 && s[i-3] == s[i-2] && canb[i-3]){
					canb[i] = true;
				}
			}
		}
		cout << (canb[sz(s)] ? "YES" : "NO" ) << endl;
	}
}