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

vi queens;
char grid[13][13] = {{0}};

int n_q_search(int i, int n, int mask){
	if (i == n) {
		// for(auto & q : queens){
		// 	cout << q << endl;
		// }
		// cout << endl;
		return 1;
	}
	int tot = 0;
	rep(j,0,n){
		if ( (mask & (1<<j)) && !grid[i][j] ) {
			bool w = true;
			rep(k,0,i){
				if (abs(queens[k] - j) == abs(k-i) ) {
					w = false;
				}
			}
			if (w){
				queens.push_back(j);
				tot += n_q_search(i+1, n, mask ^ (1<<j));
				queens.pop_back();
			}
		}
	}
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	while(n != 0){
		rep(i,0,n) rep(j,0,n) grid[i][j] = 0;
		rep(i,0,m){
			int a,b;
			cin >> a >> b;
			grid[a][b] = 1;
		}
		cout << n_q_search(0, n, (1<<n)-1) << endl;

		cin >> n >> m;
	}
}