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
const int MX = 2e5+7;
const ll inf = 1e18;
int m, k;
ll tlog[MX] = {0};

int n;
vector<pii> adj1[MX], adj2[MX];
ll d[MX] = {0};
void dij(int s){
	rep(i,0,n+1) d[i]=1e18;
	d[s]=0;
	using pli = pair<ll, int>;
	priority_queue<pli, vector<pli>, greater<pli>> Q;
	Q.push({d[s], s});
	while(!Q.empty()){
		auto [dv, v] = Q.top();
		Q.pop();
		if (d[v]!=dv) continue;
		for(auto [to, len]: adj1[v]){
			if (d[v]+len < d[to]){
				d[to] = d[v]+len;
				Q.push({d[to],to});
			}
		}
	}
	rep(i,0,n+1) for(auto [to, len]: adj1[i]){
		if (d[i]+len==d[to]) adj2[i].push_back({to, len});
	}
}

int nx[MX] = {0}, vis[MX] = {0}, res[MX] = {0};
int dfs(int v, int i, int t) {
	if (d[v]==tlog[i]) {
		i++;
	} else if (d[v]>tlog[i]) {
		return 0;
	}
	if (v == t){
		if (i==k) return 1;
		else return 0;
	}
	if (vis[v]) return res[v];
	vis[v] = true;
	res[v] = 0;
	for(auto [to, _]: adj2[v]){
		int f = dfs(to, i, t);
		if (f){
			nx[v] = to;
			res[v] = min(res[v]+f, 2);
		}
	}
	return res[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	rep(i,0,m){
		int u,v,h;
		cin >> u >> v >> h;
		adj1[u].push_back({v, h});
	}
	rep(i,0,k){
		cin >> tlog[i];
	}
	sort(tlog, tlog+k);
	tlog[k] = inf;
	dij(1);
	int f = dfs(1, 0, n);
	if (f == 0){
		cout << 0 << endl;
	} else if (f == 2){
		cout << 1 << endl;
	} else {
		vi ans;
		int cur = 1;
		nx[n] = -1;
		while(cur != -1){
			ans.push_back(cur);
			cur = nx[cur];
		}
		cout << sz(ans) << endl;
		rep(i,0,sz(ans)){
			cout << ans[i] << endl;
		}
	}
}