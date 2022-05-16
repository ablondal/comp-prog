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
	int M = 1;
	int m = 1;
	string s;
	cin >> s;
	rep(i,1,sz(s)){
		if (s[i] == s[i-1]) m++;
		else m = 1;
		M = max(M, m);
	}
	cout << M << endl;
}