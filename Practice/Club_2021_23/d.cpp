#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = (1<<18)+7;

double DP[MAXN][18] = {{0}};

double p[20][20]; // Chance that i wins over j: p[i][j]


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		rep(j,0,n){
			cin >> p[i][j];
		}
	}
	DP[1][0] = 1;
	rep(mask, 2, (1<<n)){
		rep(i, 0, n){
			if ( !(mask & (1<<i)) ) continue;
			rep(j,0,n){
				if ( !(mask & (1<<j)) ) continue;
				double res;
				res = p[i][j] * DP[mask ^ (1<<j)][i];
				res += p[j][i] * DP[mask ^ (1<<i)][j];
				DP[mask][i] = max(DP[mask][i], res);
			}
		}
	}
	double M = 0;
	rep(i,0,n){
		M = max(M, DP[(1<<n)-1][i]);
	}
	cout << setprecision(18) << M << endl;
}