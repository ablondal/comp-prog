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
	unordered_map<char, int> M;
	rep(i,0,sz(s)){
		M[s[i]]++;
	}
	string a;
	char aa = 0;
	for(auto [c, b] : M){
		while(b>1){
			a.push_back(c);
			b-=2;
		}
		if (b == 1) {
			if (aa != 0){
				cout << "NO SOLUTION" << endl;
				exit(0);
			}
			aa = c;
		}
	}
	string b(all(a));
	reverse(all(b));
	if (aa) {
		a.push_back(aa);
	}
	cout << a + b << endl;
}