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

struct custom_hash {
	// From https://codeforces.com/blog/entry/62393
    const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(pii x) const {
    	return splitmix64( x.first ^ (x.second>>1) + FIXED_RANDOM );
    }

    size_t operator()(pll x) const {
    	return splitmix64( x.first ^ (x.second>>1) + FIXED_RANDOM );
    }
};

gp_hash_table<pll, vector<int>, custom_hash> M;

// map<tuple<int, int, int, int>, vector<int>> M; // OG X, Y, and dx, dy

pll g_coords(pii a, pii b){
	ll x = a.first - b.first;
	ll y = a.second - b.second;
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
	return { (x<<32) + ax, (y << 32) + ay};
	// return {ax, ay, x, y};
}

int n;

bool poss(vector<set<int>> &VS, int l, set<int> &sofar, int i){
	if ( (sz(sofar) + 2*l) >= n) {
		return true;
	}
	if (i >= sz(VS)) return false;
	if ( (sz(sofar) + sz(VS[i])*l) < n) {
		return false;
	}
	vector<int> added;
	while(i < sz(VS) && sz(VS[i]) > 2){
		for(auto a: VS[i]) {
			if (!sofar.count(a)) {
				sofar.insert(a);
				added.push_back(a);
			}
		}
		if (poss(VS, l-1, sofar, i+1)) {
			return true;
		}
		for(auto a: added) {
			sofar.erase(a);
		}
		added.clear();

		i++;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<pii> pts(n);
	rep(i,0,n){
		cin >> pts[i].first >> pts[i].second;
	}
	int ct;
	rep(i,0,n){
		// cout << i << endl;
		rep(j,i+1,n){
			ct ++;
			auto tup = g_coords(pts[i], pts[j]);
			ct += tup.first;
			// M[tup].push_back(i);
			// M[tup].push_back(j);
		}
	}
	// cout << ct << endl;
	// Create vector of sets
	vector<set<int>> VS;
	for(auto &[tup, s]: M){
		if (sz(s) == 2) break;
		VS.emplace_back(all(s));
	}
	sort(all(VS), [](set<int> &a, set<int> &b){
		return sz(a) > sz(b);
	});
	cout << "sorted" << endl;

	// test print
	for(auto &vs: VS){
		for(auto &el: vs){
			cout << el << " ";
		}
		cout << endl;
	}

	set<int> sofar;
	if (poss(VS, 3, sofar, 0)) {
		cout << "possible" << endl;
	} else {
		cout << "impossible" << endl;
	}
}