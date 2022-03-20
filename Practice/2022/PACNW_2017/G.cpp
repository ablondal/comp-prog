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
const int NX = 1007;
const int MX = 5007;
vector<pair<int, pair<int, int>>> adj[NX];
int cur;
char vis[NX];

bool DFS(int v, int t){
	if (vis[v]) return false;
	if (v==t) return true;
	vis[v] = true;
	for(auto& [e, iv] : adj[v]){
		if (cur >= iv.first && cur < iv.second) {
			if (DFS(e,t)) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> ival;
	int n, m, k, s, t;
	cin >> n >> m >> k >> s >> t;
	ival.insert(1);
	ival.insert(k+1);
	rep(i,0,m){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		d = min(d+1, k+1);
		adj[a].push_back({b, {c,d}});
		ival.insert(c);
		ival.insert(d);
	}
	vi delim(all(ival));
	ll tot = 0;
	for(int i=0; i<sz(delim)-1; ++i){
		cur = delim[i];
		memset(vis, false, n+5);
		tot += (delim[i+1]-delim[i]) * DFS(s, t);
	}
	cout << tot << endl;
}