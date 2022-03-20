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
	set<string> S;
	int p,n, a = -1;
	cin >> p >> n;
	rep(i,0,n){
		string s;
		cin >> s;
		S.insert(s);
		if (sz(S) == p && a == -1){
			a = i+1;
		}
	}
	if (a==-1) {
		cout << "paradox avoided" << endl;
	} else {
		cout << a << endl;
	}
	// cout << (a == -1 ? "paradox avoided" : a) << endl;
}