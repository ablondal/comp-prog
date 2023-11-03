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
	string s, t;
	getline(cin, s);
	getline(cin, t);
	// cout << s << t << endl;
	int i=0, j=0;
	set<char> badd;
	while(i != sz(s)){
		while (s[i] != t[j]) {
			badd.insert(t[j]);
			j++;
		}
		i++; j++;
	}
	if (j != sz(t)) badd.insert(t[j]);
	for(auto c: badd){
		cout << c;
	}
	cout << endl;
}