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
const int MOD = 9901;

char adj[12][12] = {{0}};
int DP[1<<12][12] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	rep(T, 1, t+1){
		int n, k;
		cin >> n >> k;
		rep(i,0,n) rep(j, 0, n){
			if (i!=j) adj[i][j] = 1;
		}
		rep(i,0,k){
			int u, v;
			cin >> u >> v;
			u--; v--;
			adj[u][v] = adj[v][u] = 0;
		}

		rep(i,0, (1<<n) ) rep(j,0,n) DP[i][j] = 0;
		DP[1][0] = 1;
		rep(m, 1, (1<<n)){
			rep(from, 0, n){
				if ( !(m & (1<<from)) ) continue;
				// cout << "from " << m << " " << from << endl;
				rep(to, 0, n){
					if (m & (1<<to) || !adj[to][from]) continue;
					DP[m | (1<<to)][to] += DP[m][from];
					DP[m | (1<<to)][to] %= MOD;
				}
			}
		}
		int tot = 0;
		rep(i,1,n){
			if (adj[0][i]) tot += DP[ (1<<n)-1 ][i];
		}
		tot %= MOD;
		tot *= 4951; // divide by 2
		tot %= MOD;



		cout << "Case #" << T << ": " << tot << endl;
	}
}