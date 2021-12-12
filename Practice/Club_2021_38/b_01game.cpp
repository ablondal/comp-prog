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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n1 = 0;
		int n0 = 0;
		for(auto c : s) {
			if (c=='0') n0++;
			else n1++;
		}
		int moves = min(n0, n1);
		cout << (moves % 2 == 0 ? "NET" : "DA") << endl;
	}
}