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
const int NX = 200007;

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
	void add(ll k, ll m) { // kx + m
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

LineContainer flights_out[NX];
ll fr[NX], to[NX], S[NX], E[NX];
ll M[NX], K[NX];
char v[NX] = {0};

priority_queue<pair<int, int>> Q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	rep(i,0,m){
		cin >> fr[i] >> to[i] >> S[i] >> E[i];
		Q.push({E[i], i});
	}
	flights_out[n].add(0, 0);
	while(!Q.empty()){
		auto [_, i] = Q.top();
		Q.pop();
		if (!v[i]){
			v[i] = true;
			if (flights_out[to[i]].empty()) {
				continue;
			}
			ll newP;
			if (to[i] != n){
				newP = E[i]*E[i] - flights_out[to[i]].query(E[i]);
			} else {
				newP = 0;
			}
			// cout << fr[i] << " " << newP << endl;
			M[i] = -newP - (S[i]*S[i]);
			K[i] = 2*S[i];
			Q.push({S[i], i});
		} else {
			flights_out[fr[i]].add(K[i], M[i]);
			// cout << fr[i] << "+=" << K[i] << "x + " << M[i] << endl;
		}
	}
	cout << -flights_out[1].query(0) << endl;
}