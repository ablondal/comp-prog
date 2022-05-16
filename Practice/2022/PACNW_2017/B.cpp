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
const int MX = 1<<12 + 7;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	vi p(n);
	rep(i,0,n) cin >> p[i];
	ll M = 0, Mi = 0;
	rep(i,0,n){
		M = max(M, (ll)p[i]);
		if (M == p[i]) Mi = i;
	}

	set<tuple<int, int, int, int>> ToDo, ToDo2;
	map<tuple<int, int, int, int>, int> DP;
	// cout << Mi << endl;
	DP[{0, 0, 0, Mi}] = 1;
	ToDo.insert({0, 0, 0, Mi});
	rep(t,0,n){
		cout << sz(ToDo) << endl;
		ToDo2.clear();
		for(auto &[mask, xused, qi, i] : ToDo){
			int us = __builtin_popcount(mask);
			for(int j=0; j<n; ++j){
				if ( ((1<<j) & mask) || j==i ) continue;
				int qj = qi;
				qj = max(qj, p[i]+qi+1-p[j]);
				if (qj <= (x-xused)/(n-us) ){
					tuple<int, int, int, int> ns{mask | (1<<j), xused+qj, qj, j};
					DP[ns] += DP[{mask, xused, qi, i}];
					ToDo2.insert(ns);
				}
			}
		}
		// for(auto & a : ToDo2){
		// 	auto& [b,c,d,e] = a;
		// 	cout << b << " " << c << " " << d << " " << e << ": " << DP[a] << endl;
		// }
		swap(ToDo2, ToDo);
	}
	ll tot = 0;
	for(auto& a : ToDo){
		tot += DP[a];
	}
	cout << tot << endl;
}