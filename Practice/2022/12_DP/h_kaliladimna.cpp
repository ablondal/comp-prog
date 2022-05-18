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
	bool operator<(const Line& o) const {return k < o.k;}
	bool operator<(ll x) const { return p < x;}
};

struct LineContainer : multiset<Line, less<>> {
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b){
		return a / b - ((a^b)<0 && a % b);
	}
	bool isect(iterator x, iterator y){
		if (y==end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m){
		auto z = insert({k, m, 0}), y = z++, x = y;
		while(isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while((y=x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x){
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i,0,n) cin >> a[i];
	rep(i,0,n) cin >> b[i];
	LineContainer LC;
	LC.add(-b[0], -b[0]);
	ll c_cost = 0;
	rep(i,1,n){
		ll mm = LC.query(a[i]-1);
		c_cost = mm - b[i];
		LC.add(-b[i], c_cost);
	}
	cout << -c_cost << endl;
}