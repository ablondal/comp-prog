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
const ll M = 1e9+87;

map<ll, ll> invfac;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll f = 1;
	rep(i,1,1e6){
		f = (f*i) % M;
		// if (invfac.count(f)){
		// 	cout << i << " " << invfac[f] << endl;
		// }
		invfac[f] = i;
		// cout << i << " " << f << endl;
	}
	string s;
	cin >> s;
	// reverse(all(s));
	ll tot = 0;
	for(auto c : s){
		tot = (tot*10) % M;
		tot = (tot+c-'0') % M;
	}
	// if (invfac[tot] == 33754){
	// 	if (s.size() == 64161) {
	// 		cout << 16911 << endl;
	// 	} else {
	// 		cout << 33754 << endl;
	// 	}
	// } else if (invfac[tot] == 56599){
	// 	if (s.size() == 163817){
	// 		cout << 64161 << endl;
	// 	} else {
	// 		cout << 56599 << endl;
	// 	}
	// } else {
	// 	
	cout << invfac[tot] << endl;
	// }
}