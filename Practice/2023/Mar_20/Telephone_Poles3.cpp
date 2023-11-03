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

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> poles(n+1);
	rep(i,0,n+1){
		poles[i].push_back(-3000);
		string s;
		cin >> s;
		rep(j,0,m+1){
			if (s[j] == '1'){
				poles[i].push_back(j);
			}
		}
		poles[i].push_back(6000);
		poles[i].push_back(6001);
	}
	vector<int> x_i(n+1, 0);

	ll tot = 0;

	rep(x,0,m+1){
		LineContainer LC;
		rep(y,0,n+1){
			if ( abs(poles[y][x_i[y]] - x) > abs(poles[y][x_i[y]+1] - x)) x_i[y]++;
			int dx = abs(poles[y][x_i[y]] - x);
			// For any point (x, i), dist^2 = (dx)^2 + (i - y)^2
			// = dx^2 + y^2 - 2yi + i^2
			// we want minimum
			// cout << dx << endl;
			LC.add(2*y, -(dx*dx + y*y));
		}
		rep(i,0,n+1){
			// cout << -(LC.query(i) - (i*i)) << '\t'; 
			tot -= (LC.query(i) - ((ll)i*i));
		}
		// cout << endl;
	}
	cout << tot << endl;


}