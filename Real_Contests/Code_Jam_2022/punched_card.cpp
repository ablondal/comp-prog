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
	rep(T, 1, t+1){
		int a, b;
		cin >> a >> b;
		vector<string> c;
		string s, e;
		rep(i,0,b){
			s += "+-";
			e += "|.";
		}
		s += "+";
		e += "|";
		rep(i,0,a){
			c.emplace_back(all(s));
			c.emplace_back(all(e));
		}
		c.emplace_back(all(s));
		c[0][0] = c[0][1] = c[1][0] = '.';
		cout << "Case #" << T << ":" << endl;
		for(auto& y : c){
			cout << y << endl;
		}

	}
}