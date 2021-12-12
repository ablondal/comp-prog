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
const int MAXN = (1<<21) + 1;
const ll M = 1e9+7;

ll DP[22][MAXN] = {{0}};
int a[22][22] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		rep(j,0,n){
			cin >> a[i][j];
		}
	}
	DP[0][0] = 1;
	for(int i=0; i<n; ++i){
		for(int mask=0; mask<(1<<n); ++mask){
			if (DP[i][mask]==0) continue;
			for(int j=0; j<n; ++j){
				if ( a[i][j] && !( (1<<j) & mask ) ) {
					DP[i+1][mask | (1<<j)] += DP[i][mask];
					DP[i+1][mask | (1<<j)] %= M;
				}
			}
		}
	}
	ll tot = 0;
	for(int mask=0; mask<(1<<n); ++mask){
		tot = (tot + DP[n][mask]) % M;
	}
	cout << tot << endl;
}