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
const int MX = 500*500+7;
const ll inf = 1e18;

ll grid[507][507] = {{0}};

ll minrow[MX][507];
ll mincol[MX][507];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<vector<pair<int, int>>> inds(k);
	rep(i,0,n){
		rep(j,0,n){
			int a;
			cin >> a;
			inds[a-1].push_back({j, i});
		}
	}

	rep(i,0,k){
		if (inds[i].empty()){
			cout << -1 << endl;
			return 0;
		}
	}

	rep(i,0,k+1){
		rep(j,0,n+1){
			minrow[i][j] = inf;
			mincol[i][j] = inf;
		}
	}
	for(auto &[x,y] : inds[0]){
		mincol[0][x] = 0;
		minrow[0][y] = 0;
		grid[x][y] = 0;
		// cout << 0 << " " << x << " " << y << endl;
	}

	rep(i,1,k){
		for(auto &[x,y] : inds[i]){
			ll m = inf;
			rep(d,0,n){
				if (x+d<n) m = min(m, mincol[i-1][x+d] + d*d);

				if (y+d<n) m = min(m, minrow[i-1][y+d] + d*d);

				if (x-d>=0) m = min(m, mincol[i-1][x-d] + d*d);

				if (y-d>=0) m = min(m, minrow[i-1][y-d] + d*d);

				// cout << m << endl;
			}
			mincol[i][x] = min(mincol[i][x], m);
			minrow[i][y] = min(minrow[i][y], m);
			grid[x][y] = m;
		}
	}
	ll m = inf;
	for(auto& [x,y] : inds[k-1]){
		m = min(m, grid[x][y]);
	}
	if (m < inf) cout << m << endl;
	else cout << -1 << endl;
}