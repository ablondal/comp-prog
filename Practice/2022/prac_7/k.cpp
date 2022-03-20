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
const int MAXN = 1e5+7;


struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return lcm(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	Tree(vector<pair<double,ll>> &V) : s(2*sz(V), unit), n(sz(V)) {
		rep(i,n,2*n){
			s[i] = V[i-n].second;
		}
		for(int i=n-1; i>=0; --i){
			s[i] = f(s[2*i], s[2*i+1]);
		}
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = 1, rb = 1;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int bin_f(double val, vector<pair<double, ll>> &plan){
	int lo = -1, hi = plan.size();
	while(hi-lo>1){
		int md = (hi+lo)/2;
		if (plan[md].first<=val) lo = md;
		else hi = md;
	}
	return hi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p, r;
	cin >> p >> r;
	vector<pair<double, ll>> plan(p);
	rep(i,0,p){
		cin >> plan[i].first >> plan[i].second;
	}
	vector<pair<double, double>> Q(r);
	rep(i,0,r){
		cin >> Q[i].first >> Q[i].second;
	}
	sort(all(plan));
	Tree T(plan);
	// rep(i,0,p){
	// 	T.update(i,plan[i].second);
	// }
	rep(i,0,r){
		int l = bin_f(Q[i].first, plan);
		int r = bin_f(Q[i].second, plan);
		// cout << l << " " << r << endl;
		cout << T.query(l, r) << endl;
	}

	
}