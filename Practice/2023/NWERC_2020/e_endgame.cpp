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

inline bool valid(int n, int x, int y){
	return (x > 0) && (y > 0) && (x <= n) && (y <= n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ax, ay, bx, by;
	cin >> n >> ax >> ay >> bx >> by;
	vector<pii> mvs(n);
	rep(i,0,n) cin >> mvs[i].first >> mvs[i].second;
	mvs.push_back({0, 0});
	set<pii> B, A2;
	vector<pii> A1;
	for(auto [dx, dy] : mvs){
		if (valid(n, ax+dx, ay+dy)) A1.push_back({ax+dx, ay+dy});
		if (valid(n, bx-dx, by-dy)) A2.insert({bx-dx, by-dy});
		if (valid(n, bx+dx, by+dy)) B.insert({bx+dx, by+dy});
	}
	for(auto a: A1){
		if (A2.count(a)){
			cout << "Alice wins" << endl;
			return(0);
		}
	}
	if (n < 100) {
		vector<vector<bool>> reachable(n+1, vector<bool>(n+1));
		for(auto [x1, y1]: mvs) for(auto [x2, y2] : mvs){
			// auto [x1, y1] = mvs[i];
			// auto [x2, y2] = mvs[j];
			int nx = bx + x1 + x2;
			int ny = by + y1 + y2;
			if (valid(n, nx, ny)) {
				reachable[nx][ny] = true;
			}
		}
		rep(i,1,n+1) rep(j,1,n+1){
			if (!reachable[i][j]){
				cout << "tie" << " " << i << " " << j << endl;
				return(0);
			}
		}
		cout << "Bob wins" << endl;
	} else {
		srand(time(NULL));
		while(true){
			int x = 1 + (rand() % n);
			int y = 1 + (rand() % n);
			bool w = true;
			rep(i,0,n+1){
				auto [dx, dy] = mvs[i];
				int nx = x - dx;
				int ny = y-dy;
				if (valid(n, nx, ny)) {
					if (B.count({nx, ny})) {
						w = false;
						break;
					}
				}
			}
			if (w) {
				cout << "tie" << " " << x << " " << y << endl;
				return(0);
			}
		}
	}
}