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
	int n = sz(s);
	vi perm(n);
	iota(all(perm), 0);
	set<string> S;
	do {
		string a(n, 0);
		rep(i,0,n){
			a[perm[i]] = s[i];
		}
		S.insert(a);
	} while (next_permutation(all(perm)));
	cout << sz(S) << endl;
	for(auto p : S){
		cout << p << endl;
	}
}