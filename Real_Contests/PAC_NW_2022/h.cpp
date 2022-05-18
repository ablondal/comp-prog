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
	string s;
	cin >> s;
	string t = s;
	reverse(all(t));
	s += s;
	if (s.find(t.substr(1,sz(t))) != string::npos && s.find(t.substr(0,sz(t)-1)) != string::npos){
		cout << 1 << endl;
	} else{
		cout << 0 << endl;
	}
}