#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

const int mx_tries = 1e3;
int n;

tuple<int, int, int, int> get_line(pii a, pii b){
	ll x = a.first - b.first;
	ll y = a.second - b.second;
	if (x < 0) {
		x *= -1;
		y *= -1;
	}
	if (x == 0) {
		// y = 1;
		return {a.first, 0, 0, 1};
	}
	if (y == 0) {
		// x = 1;
		return {0, a.second, 1, 0};
	}
	int g = gcd(abs(x), abs(y));
	x /= g;
	y /= g;
	int r = a.first / x;
	int ax = a.first - r * x;
	int ay = a.second - r * y;
	if (ax < 0) {
		ax += x;
		ay += y;
	}
	return {ax, ay, x, y};
	// return {ax, ay, x, y};
}

inline bool on(tuple<int, int, int, int> &line, pii &pt){
	auto &[x, y, a, b] = line;
	int xx = pt.first - x;
	int yy = pt.second - y;
	if (a == 0) {
		return xx == 0;
	}
	if (b == 0) {
		return yy == 0;
	}
	int r = xx / a;
	xx -= a * r;
	yy -= b * r;
	if (xx == 0 && yy == 0) return true;
	return false;

	// if (xx < 0) {
	// 	xx *= -1;
	// 	yy *= -1;
	// }
	// int g = gcd(abs(xx), abs(yy));
	// xx /= g;
	// yy /= g;
	// if (xx == a && yy == b) return true;
	// return false;
}

vector<pii> online(tuple<int, int, int, int> &line, vector<pii> &pts){
	vector<pii> V;
	rep(i,0,sz(pts)){
		if (on(line, pts[i])) {
			V.push_back(pts[i]);
		}
	}
	return V;
}

bool poss(set<pii> &left, int l) {
	if (2*l >= sz(left)) return true;
	if (l == 0) {
		return false;
	} 
	vector<pii> ppts(all(left));
	int k = sz(ppts);
	set<tuple<int, int, int, int>> tried;
	rep(t, 0, mx_tries) {
		int i = rand() % k;
		int j = rand() % k;
		if (i == j) continue;
		auto line = get_line(ppts[i], ppts[j]);
		if (tried.count(line)) continue;
		tried.insert(line);
		// auto & [q,w,e,r] = line;
		// cout << q << " " << w << " " << e << " " << r << endl;

		auto vline = online(line, ppts);
		// cout << sz(vline) << endl;
		if (sz(vline) * l < sz(left)) continue;

		for(auto p: vline){
			left.erase(p);
		}
		if (poss(left, l-1)) {
			return true;
		}
		for(auto p: vline){
			left.insert(p);
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(NULL));
	cin >> n;
	vector<pii> pts(n);
	rep(i,0,n){
		cin >> pts[i].first >> pts[i].second;
	}
	int ct;

	set<pii> left(all(pts));

	
	if (poss(left, 3)) {
		cout << "possible" << endl;
	} else {
		cout << "impossible" << endl;
	}
}