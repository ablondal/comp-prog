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

int DP[3007][3007] = {{0}};
int P[3007][3007] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	string t;
	cin >> s >> t;
	for(int i=0; i<sz(s); ++i){
		for (int j=0; j<sz(t); ++j){
			if (s[i] == t[j]){
				DP[i+1][j+1] = DP[i][j] + 1;
				P[i+1][j+1] = 0; 
			}else if (DP[i+1][j] > DP[i][j+1]){
				P[i+1][j+1] = -1;
				DP[i+1][j+1] = DP[i+1][j];
			}else{
				P[i+1][j+1] = 1;
				DP[i+1][j+1] = DP[i][j+1];
			}
			// cout << DP[i+1][j+1] << " ";
		}
		// cout << endl;
	}
	string res;
	int i = sz(s), j = sz(t);
	while(i && j){
		if (P[i][j] == 0){
			res.push_back(s[i-1]);
			i--;
			j--;
		} else if (P[i][j] == -1){
			j--;
		} else {
			i--;
		}
	}
	reverse(all(res));
	cout << res << endl;
}