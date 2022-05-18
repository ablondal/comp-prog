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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, n;
	cin >> c >> n;
	int intr = 0;
	bool w = true;
	rep(i,0,n){
		int u, v, x;
		cin >> u >> v >> x;
		if (u > intr) w = false;
		intr -= u;
		intr += v;
		if (intr > c) w = false;
		if (x && c-intr > 0) w = false;
	}
	if (intr != 0) w = false;
	cout << (w ? "possible" : "impossible" ) << endl;
}