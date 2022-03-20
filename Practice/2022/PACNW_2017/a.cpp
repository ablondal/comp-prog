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
	bool allodd = true;
	rep(i,0,sz(s)){
		rep(j,i+1,sz(s)){
			string a = s.substr(i,j-i);
			string b = a;
			reverse(all(b));
			if (b == a && sz(a)%2 == 0) allodd = false;
		}
	}
	cout << (allodd ? "Odd." : "Or not.") << endl;
}