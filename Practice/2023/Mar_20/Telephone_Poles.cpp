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

int G[2007][2007] = {{0}};
// set<pair<int, int>> p[2007][2007];

using pt = tuple<short, short, short, short>;

int dd[12][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}, {0, 3}, {0, -3}, {3, 0}, {-3, 0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pt> sinks;
	rep(i,0,n+1){
		string s;
		cin >> s;
		rep(j,0,m+1){
			G[i][j] = 1LL<<30;
			if (s[j] == '1'){
				sinks.push_back({i, j, i, j});
				G[i][j] = 0;
			}
		}
	}

	using pii = pair<int, pt>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	for(auto a: sinks){
		q.push({0, a});
	}
	while(!q.empty()){
		auto [i, j, oi, oj] = q.top().second;
		ll d_v = q.top().first;
		q.pop();
		if (G[i][j] != d_v) continue;

		for(auto [dx, dy] : dd){
			int ni = i+dx;
			int nj = j+dy;
			if (ni<0 || ni>n || nj<0 || nj>m){
				continue;
			}
			int nd = (nj-oj)*(nj-oj) + (ni-oi)*(ni-oi);
			if (nd < G[ni][nj]){
				// p[ni][nj].clear();
				// p[ni][nj].insert({oi, oj});
				G[ni][nj] = nd;
				q.push({nd, {ni, nj, oi, oj}});
			}
			// else if (nd == G[ni][nj] && L[ni][nj].count({oi, oj}) == 0) {
			// 	L[ni][nj].insert({oi, oj});
			// 	q.push({nd, {ni, nj, oi, oj}});
			// }
		}
	}
	ll tot = 0;
	rep(i,0,n+1){
		rep(j,0,m+1){
			// cout << G[i][j] << "\t";
			tot += (ll)G[i][j];
		}
		// cout << endl;
	}
	cout << tot << endl;

}