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
const int MX = 10007;

bitset<MX> gs[MX] = {0};
map<pii, int> M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int g;
	cin >> g;
	rep(i,0,g){
		int u,v;
		cin >> u >> v;
		M[{u,v}]++;
		gs[u][v] = true;
	}
	int m;
	cin >> m;
	int tot = 0;
	rep(i,0,m){
		int u, v, r;
		cin >> u >> v >> r;
		int r2 = r*r;
		rep(x, max(u-r, 0), min(MX-1, u+r)+1){
			rep(y, max(v-r, 0), min(MX-1, v+r)+1){
				if ( (x-u)*(x-u) + (y-v)*(y-v) <= r*r && gs[x][y]) {
					tot += M[{x, y}];
					gs[x][y] = false;
				}
			}
		}
	}
	cout << g-tot << endl;

}