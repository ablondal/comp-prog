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
	cin >> s >> t;
	vector<vector<int>> DP(sz(s)+1, vi(sz(t)+1, 0));
	vector<vector<int>> p(sz(s)+1, vi(sz(t)+1, -1));
	rep(i,0,sz(s)){
		rep(j,0,sz(t)){
			if (s[i] == t[j]) {
				DP[i+1][j+1] = DP[i][j] + 1;
				p[i+1][j+1] = 3;
			}
			if (DP[i][j+1] > DP[i+1][j+1]){
				DP[i+1][j+1] = DP[i][j+1];
				p[i+1][j+1] = 1;
			}
			if (DP[i+1][j] > DP[i+1][j+1]){
				DP[i+1][j+1] = DP[i+1][j];
				p[i+1][j+1] = 2;
			}
		}
	}
	string ans;
	int i = sz(s), j = sz(t);
	while(p[i][j] != -1){
		if (p[i][j] == 3){
			ans.push_back(s[i-1]);
			i--;
			j--;
		} else if (p[i][j] == 2){
			j--;
		} else if (p[i][j] == 1){
			i--;
		}
	}
	reverse(all(ans));
	cout << ans << endl;
}