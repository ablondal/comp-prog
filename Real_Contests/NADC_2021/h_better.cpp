#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9+7;
const ll p = 31;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	vector<ll> inall;
	set<ll> strs;
	rep(si,0,t){
		string s;
		cin >> s;
		strs.clear();
		rep(i,0,s.size()){
			ll h = 0;
			rep(j,i,s.size()){
				h *= p;
				h += s[j]-'a'+1;
				h %= MOD;
				strs.insert(h + (MOD * (j-i) ));	
			}
		}
		// cout << si << endl;
		if (si == 0){
			inall.assign(all(strs));
		}else{
			vector<ll> outp(max(inall.size(), strs.size()));
			auto it = set_intersection(all(inall), all(strs), outp.begin());
			outp.resize(it-outp.begin());
			inall.assign(all(outp));
		}
		// rep(i,0,inall.size()){
		// 	cout << inall[i] << " ";
		// }
		// cout << endl << endl;
	}
	if (inall.size()==0){
		cout << 0 << endl;
	}else{
		cout << (inall[inall.size()-1] / MOD)+1 << endl;
	}
}