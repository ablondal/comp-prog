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
const int MX = 100007;

bitset<100007> b, p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int f;
	cin >> f;
	bool w = true;
	rep(i,0,f){
		int t, n;
		cin >> t >> n;
		b.reset();
		p.reset();
		rep(i,0,t+1) p[i] = b[i] = true;
		rep(i,0,n){
			int u, v;
			cin >> u >> v;
			int c = v-u;
			p = (p << c) | (p >> c);
			p = p & b;
		}
		if (!p.count()) w = false;
	}

	cout << (w ? "possible" : "impossible") << endl;
}