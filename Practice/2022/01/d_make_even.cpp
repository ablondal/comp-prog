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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w;
	cin >> h >> w;
	int grid[500][500] = {{0}};
	rep(i,0,h) {
		rep(j,0,w) {
			int a;
			cin >> a;
			grid[i][j] = (a % 2);
		}
	}
	int ly = 0, lx = 0;
	bool has = 0;
	vector<tuple<int, int, int, int>> ans;
	rep(i,0,h){
		int dir = (i % 2 ? 1 : -1);
		int st = (i % 2 ? 0 : w-1);
		for(int j = st; j>=0 && j<w; j += dir){
			if (has) {
				ans.push_back({ly, lx, i+1, j+1});
			}
			has ^= grid[i][j];
			ly = i+1;
			lx = j+1;
		}
	}
	cout << sz(ans) << endl;
	for(auto [a, b, c, d] : ans){
		cout << a << " " << b << " " << c << " " << d << endl;
	}
}