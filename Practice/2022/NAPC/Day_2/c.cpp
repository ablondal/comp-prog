#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll inf = 1e17;

ll DPmin[(1<<15)][15], DPmax[(1<<15)][15];
ll D[15][15] = {{0}};
int n;
ll L;

bool dfs(int from, int m, ll curd) {
	// cout << from << " " << m << " " << curd << endl;
	if (m == ((1<<n)-1)) {
		if (curd + D[from][0] == L) return true;
		return false;
	}

	if (from != 0) {
		int notm = (~m) & ((1<<n)-1);
		notm = notm | (1<<from) | (1);
		// cout << curd + DPmin[notm][from] << " " << curd + DPmax[notm][from] << endl;
		if (curd + DPmin[notm][from] > L || curd + DPmax[notm][from] < L) return false;
	}
	rep(to,0,n){
		if ((~m) & (1<<to)) {
			if (dfs(to, m | (1<<to), curd + D[from][to])) {
				return true;
			}
		}
	}
	return false;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> L;
	rep(i,0,n) rep(j,0,n){
		cin >> D[i][j];
	}
	rep(i,0,(1<<n)) rep(j,0,n){
		DPmin[i][j] = inf;
		DPmax[i][j] = -inf;
	}
	DPmin[1][0] = DPmax[1][0] = 0;

	rep(m,1,(1<<n)) {
		rep(from, 0, n){
			if (m & (1<<from)) {
				// cout << "min: " << m << " " << from << " " << DPmin[m][from] << endl;
				// cout << "max: " << m << " " << from << " " << DPmax[m][from] << endl;
				rep(to, 0, n) {
					if ( !(m & (1<<to)) ) {
						DPmin[m | (1<<to)][to] = min(DPmin[m | (1<<to)][to], DPmin[m][from] + D[from][to]);
						DPmax[m | (1<<to)][to] = max(DPmax[m | (1<<to)][to], DPmax[m][from] + D[from][to]);
						DPmin[m | (1<<to)][to] = min(DPmin[m | (1<<to)][to], inf);
						DPmax[m | (1<<to)][to] = min(DPmax[m | (1<<to)][to], inf);
					}
				}
			}
		}
	}

	if (dfs(0, 1, 0)) {
		cout << "possible" << endl;
	} else {
		cout << "impossible" << endl;
	}
}