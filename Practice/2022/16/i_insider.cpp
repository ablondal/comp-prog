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

ll brute_solve(int n, string s){
	int ct = 0;
	rep(i,0,1<<n){
		bool w = false;
		rep(j,0,n-sz(s)+1){
			bool ww = true;
			rep(k,j,j+sz(s)){
				if (s[k-j]=='1' && (i & (1<<k)) == 0){
					ww = false;
					break;
				}
			}
			if (ww){
				w = true;
				break;
			}
		}
		if (w) ct++;
	}
	return ct;
}

ll DP[57][37] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	// ll a;
	// rep(i,0,sz(s)){
	// 	if (s[i] == '1') a |= (1LL << i);
	// }
	// DP[0][0] = 1;
	// rep(i,0,n){
	// 	rep(j,0,sz(s)){
	// 		if (s[j] == '*') {
	// 			DP[i+1][j+1] += 2*DP[i][j];
	// 		} else {
	// 			DP[i+1][j+1] += DP[i][j];
	// 			rep(k,0,j){
	// 				if (s[k] == '*') {
	// 					int c = 0;
	// 					rep(l,0,k) {
	// 						if (s[l] == '1' && s[j-k+l] == '*') c++;
	// 					}
	// 					DP[i+1][k] += DP[i][j] / (1<<c);
	// 					DP[i][j] -= DP[i][j] / (1<<c);
	// 				}
	// 				int c = __builtin_popcountll(a & (a>>(j-k)));
	// 				DP[i+1][k] += DP[i][j] / (1<<)
	// 			}
	// 		}
	// 	}
	// }

	rep(i,1,21) {
		cout << (1<<i) - brute_solve(i, s) << endl;
	}

	// cout << (1<<n) - brute_solve(n, s) << endl;

}