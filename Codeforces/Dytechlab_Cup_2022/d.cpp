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
typedef vector<int> vi;
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
};


// Supports .find(), []++

const ll INF = 1e18;
vector<vector<pair<int, ll>>> adj;

inline ll encode(ll node, ll w){
	return (node<<40)^w;
}

int Ws[501];

bool put_in(int i, int dist, int w){
	if (Ws[i] <= w) return 0;
	Ws[i] = w;
	return 1;
}

ll solve(){
	int ss = sz(adj)-1;

	// gp_hash_table<long long, null_type, custom_hash> dist;

	vector<ll> Q;
	vector<ll> nQ;
	ll best = INF;

	rep(i,1,ss+1) Ws[i] = 1e9+1;

	Q.push_back(encode(1, 1e9+1));
	put_in(1, 0, 1e9+1);
	// dist.insert(encode(1, 1e9+1));
	int dep = 0;
	while(!Q.empty() && dep < 3*ss){
		dep++;
		nQ.clear();
		for(auto n: Q){
			ll w = n & ((1LL<<32)-1);
			// cout << w << endl;
			n = n >> 40;
			// cout << n << endl;
			// cout << n << " " << w << endl;
			if (n == ss) {
				best = min(best, w * (dep-1));
			}
			for(auto [e, w2]: adj[n]){
				w2 = min(w, w2);
				ll e1 = encode(e, w2);
				if (put_in(e, dep, w2)){
					nQ.push_back(e1);
				}
				// if (dist.find(e1) == dist.end()) {
				// 	dist.insert(e1);
				// 	nQ.push_back(e1);
				// }
				if (w2 != w) {
					ll e2 = encode(n, w2);
					if (put_in(n, dep, w2)){
						nQ.push_back(e2);
					}
					// if (dist.find(e2) == dist.end()){
					// 	dist.insert(e2);
					// 	nQ.push_back(e2);
					// }
				}
			}
		}
		swap(Q, nQ);
	}

	return best;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		adj.clear();
		int n, m;
		cin >> n >> m;
		adj.resize(n+1);
		rep(i,0,m){
			int u, v;
			ll w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		cout << solve() << endl;
	}
}