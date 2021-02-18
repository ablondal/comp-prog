#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int xcds = 0, ycds = 0;
	vi xs(n+1, 0), ys(n+1, 0);
	ll tot = n;
	tot *= n;
	rep(i,0,m){
		int x, y;
		cin >> x >> y;
		if (!xs[x]) {
			tot -= (n-ycds);
			xs[x] = true;
			xcds++;
		}
		if (!ys[y]){
			tot -= (n-xcds);
			ys[y] = true;
			ycds++;
		}
		// if (!xs[x]) {
			
		// }
		// if (!ys[y]) {
			
		// }
		cout << tot << endl;
	}
	// cout << tot << endl;
}