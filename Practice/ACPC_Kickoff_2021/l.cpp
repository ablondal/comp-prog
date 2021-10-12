#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("max-pair.in","r",stdin);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = sz(s)-1;
		if (s[n]==s[0]) {
			cout << n-1 << endl;
		} else {
			cout << n << endl;
		}
	}
}