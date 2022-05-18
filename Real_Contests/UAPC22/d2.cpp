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

gp_hash_table<ll, ll> DPstate;

vi adj[50];
char vis[50] = {0};
int vnum = 0;
int n;

ll hcyc(ll v, ll mask){
	if (DPstate.find( (v << 51)^mask ) != DPstate.end()) {
		return DPstate[(v<<51)^mask];
	}
	ll tot = 0;
	for(auto e : adj[v]){
		if (e==0 && mask == (1LL << n)-1){
			tot += 1;
		}
		if (! (mask & (1LL << e))) {
			tot += hcyc(e, mask ^ (1LL<<e));
		}
	}

	return DPstate[(v<<51)^mask] = tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i,0,(n/2)*3){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << hcyc(0, 1) / 2 << endl;
}