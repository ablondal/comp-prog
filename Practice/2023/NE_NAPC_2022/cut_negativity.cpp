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

int grid[107][107];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> f;
	rep(i,0,n){
		rep(j,0,n){
			cin >> grid[i][j];
			if (grid[i][j] > 0){
				f.push_back({i+1, j+1, grid[i][j]});
			}
		}
	}
	cout << sz(f) << endl;
	for(auto [a, b, c]: f){
		cout << a << " " << b << " " << c << endl;
	}
}