#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 5007;
const int MOD = 1e9+7; 
const int p = 31;

ll p_pow[MAXN];

ll shash[MAXN] = {0};
ll rhash[MAXN] = {0};
int n;

bool is_eq(int l, int r, int l2, int r2){
	ll h1 = (shash[r] - shash[l] + MOD) % MOD;
	h1 *= p_pow[l2-l];
	h1 %= MOD;
	
	ll h2 = (shash[r2] - shash[l2] + MOD) % MOD;

	// cout << h1 << " " << h2 << endl;
	return h1 == h2;
}

bool is_p(int l, int r){
	ll h1 = (shash[r] - shash[l] + MOD) % MOD;

	int l2 = n-r;
	int r2 = n-l;

	ll h2 = (rhash[r2] -rhash[l2] + MOD) % MOD;

	if (l2>l) h1 = (h1 * p_pow[l2-l]) % MOD;
	else h2 = (h2 * p_pow[l-l2]) % MOD;

	return h1 == h2;
}

int ispalin[MAXN][MAXN] = {{0}};

int DP[MAXN][MAXN] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	p_pow[0] = 1;
	rep(i,1,MAXN) p_pow[i] = (p_pow[i-1] * p) % MOD;

	string s;
	cin >> s;

	string rs(all(s));
	reverse(all(rs));

	rep(i,0,sz(s)){
		shash[i+1] = (shash[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
		rhash[i+1] = (rhash[i] + (rs[i] - 'a' + 1) * p_pow[i]) % MOD;
	}

	vi n_pal(MAXN, 0);
	n = sz(s);

	// cout << is_eq(0, 2, 2, 4) << endl;

	rep(gap,1,n+1){
		rep(i,0,n+1-gap){
			int j=i+gap;
			int len = (j-i)/2;
			// cout << "find " << i << " "<< i+len << " " << j-len << " " << j << endl;
			if (is_p(i, j)){
				// cout << "ispalin 1" << endl;
				DP[i][j] = 1;
				n_pal[1]++;
			}
			
			if (j > i+1 && is_eq(i, i+len, j-len, j)){
				// cout << "iseq" << endl;
				if (DP[i][i+len] && DP[j-len][j]){
					DP[i][j] = min(DP[i][i+len], DP[j-len][j])+1;
					n_pal[DP[i][j]]++;
					// rep(k, 2, DP[i][j]+1){
					// 	n_pal[k]++;
					// }
				}
				// else{
				// 	cout << "but subs arent" << DP[i][i+len] << " " << DP[j-len][j] << endl;
				// }
				
				// n_pal[DP[i][j]]++;
			}
			
		}
	}
	for(int i = sz(s); i>1; --i){
		n_pal[i] += n_pal[i+1];
	}
	for(int i=1; i<=sz(s); ++i){
		cout << n_pal[i] << " ";
	}
	cout << endl;
	
}