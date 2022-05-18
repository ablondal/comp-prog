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
	int M = 1;
	vi DP(sz(s), 0);
	rep(i,0,sz(s)){
		DP[i] = 1;
		rep(j,0,i){
			if (s[j] < s[i]){
				DP[i] = max(DP[i], DP[j]+1);
				M = max(M, DP[i]);
			}
		}
		// cout << DP[i] << endl;
	}
	cout << 26 - M << endl;
}