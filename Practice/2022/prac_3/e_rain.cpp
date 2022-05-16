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

 double rchange[10007] = {0};
bool roof[1007] = {0};
 double DP[1007][10007] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d, t, c, r;
	cin >> d >> t >> c >> r;
	vector<pair<int, double>> raind;
	rep(i,0,c){
		int s,e,a;
		double p;
		cin >> s >> e >> p >> a;
		raind.push_back({s,p*a});
		raind.push_back({e,-p*a});
	}
	sort(all(raind));
	int i=0, j=0;
	 double cur = 0;
	while(i<=t+1 && j<sz(raind)){
		while(j<sz(raind) && raind[j].first <= i){
			cur += raind[j].second;
			j++;
		}
		rchange[i] = cur;
		// cout << cur << endl;
		i++;
	}
	rep(i,0,r){
		int s,e;
		cin >> s >> e;
		rep(j,s,e){roof[j] = 1;}
	}
	// roof[0] = 1;
	DP[0][0] = 0;
	rep(i,0,t+1){
		DP[0][i] = 0;
	}
	rep(j,1,d+1){
		DP[j][0] = 1e18;
	}
	rep(i,1,d+1) {
		rep(j,1,t+1) {
			DP[i][j] = min(
				DP[i-1][j-1] + (1-roof[i-1])*rchange[j-1],
				DP[i][j-1] + (1-roof[i])*(1-roof[i-1])*rchange[j-1]
			);
			// cout << i << " " << j << " " << DP[i][j] << endl;
		}
	}
	cout << setprecision(18) << DP[d][t] << endl;

}