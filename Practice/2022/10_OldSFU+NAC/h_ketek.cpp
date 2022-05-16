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
const int MAXN = 30007;
const ll MOD = 998244353;

vector<vector<short>> mlen, nway;

ll p26[MAXN];

ll DP[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	p26[0] = 1;
	rep(i,1,MAXN){
		p26[i] = (p26[i-1]*26)%MOD;
	}
	string s;
	cin >> s;
	int hs = (sz(s)+3)/2;
	int h = sz(s)/2;
	mlen.resize(hs, vector<short>(hs, 0));
	nway.resize(hs, vector<short>(hs, 0));

	rep(i,0,hs){
		mlen[i][hs-1] = mlen[hs-1][i] = 0;
		nway[i][hs-1] = nway[hs-1][i] = 0;
	}

	for(int i=hs-2; i>=0; --i){
		for(int j=hs-2; j>=0; --j){
			if (s[i]=='?' && s[h+j]=='?') {
				mlen[i][j] = mlen[i+1][j+1] + 1;
				nway[i][j] = nway[i+1][j+1] + 1;
			} else if (s[i]=='?' || s[h+j]=='?' || s[i]==s[h+j]) {
				mlen[i][j] = mlen[i+1][j+1] + 1;
				nway[i][j] = nway[i+1][j+1];
			} else {
				mlen[i][j] = 0;
				nway[i][j] = 0;
			}
			// cout << mlen[i][j] << " " << s.substr(i, hs-1-i) << " " << s.substr(h+j, hs-1-i) << endl;
		}
	}

	// We have sz(s) characters, so (sz(s)+1)/2 states
	int nst = (sz(s))/2;
	for(int i=nst; i>=0; i--){
		int stlen = (2*(nst-i)) + (sz(s) & 1);
		// cout << i << " " << stlen << endl;
		int centern = 0;
		rep(j,0,stlen) centern += s[i+j]=='?';
		// cout << s.substr(i, stlen) << " " << centern << endl;

		DP[i] = p26[centern];
		rep(j, i+1, nst+1){
			// cout << j << endl;
			// cout << "maxl between " << s.substr(i, sz(s)) << ", " << s.substr(sz(s)-j, sz(s)) << ": " << mlen[i][sz(s)-j] << endl;
			// Check if the substrings desired match
			if (mlen[i][hs-1-j] >= j-i){
				int nn = nway[i][hs-1-j] - nway[j][hs-1-j];
				// cout << s.substr(i, j-i) << " " << s.substr(sz(s)-j, j-i) << " " << nn << endl;
				DP[i] = (DP[i] + DP[j]*p26[nn]) % MOD;
			}
		}
		// cout << i << " " << DP[i] << endl;
	}
	cout << DP[0] << endl;

}