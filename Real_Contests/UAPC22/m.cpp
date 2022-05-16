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

vector<pair<int, int>> adj[1007];
set<int> to_eat;
int nv = 0;

ll dfs(int v, int p){
	ll tot = 0;
	if (to_eat.count(v)) {
		nv++;
	}
	for(auto [e, d]: adj[v]){
		if (e==p) continue;
		int nv2 = nv;
		ll d2 = dfs(e, v);
		if (nv != nv2){
			tot += d + d2;
		}
	}
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	rep(i,0,n-1){
		int s, t, d;
		cin >> s >> t >> d;
		adj[s].push_back({t, d});
		adj[t].push_back({s, d});
	}
	rep(i,0,k){
		int a;
		cin >> a;
		to_eat.insert(a);
	}
	cout << 2 * dfs(0, -1) << endl;

}