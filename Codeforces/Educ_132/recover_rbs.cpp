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

bool teststr(string s){
	int ct = 0;
	for(auto c : s){
		if (c == '(') ct++;
		else if (c == ')') ct--;
		if (ct < 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int a=0, b=0;
		for(auto c: s){
			if (c == '(') a++;
			else if (c == ')') b++;
		}
		int nopens = (sz(s)/2) - a;
		int nclose = (sz(s)/2) - b;
		if (nopens == 0 || nclose == 0) {
			cout << "YES" << endl;
			continue;
		}
		// a2 + a = sz(rbs)/2
		a = nopens;
		rep(i,0,sz(s)){
			if (s[i] != '?') continue;
			if (a>1 || a == 0) {
				s[i] = '(';
			} else {
				s[i] = ')';
			}
			a--;
		}
		if (teststr(s)) cout << "NO" << endl;
		else cout << "YES" << endl;
		
	}
}