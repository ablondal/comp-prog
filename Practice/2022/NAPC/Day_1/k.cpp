#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5+7;

vi val, comp, z, cont;
int Time, ncomps;

vi adj[MX];
int n;

int dfs(int j) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for(auto e : adj[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while( x != j);
		cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
void scc(){
	val.assign(n+1, 0); comp.assign(n+1, -1);
	Time = ncomps = 0;
	rep(i,1,n+1) if (comp[i] < 0) dfs(i);
}

int main(){
	cin.tie(0) ->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--){
		int m;
		cin >> n >> m;
		z.clear();
		rep(i,1,n+1) adj[i].clear();
		rep(i,0,m){
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		// n++;
		scc();
		vi indeg(ncomps, 0), odeg(ncomps, 0);
		int n1 = 0, n2 = 0;
		rep(i,1,n+1){
			for(auto e : adj[i]){
				if (comp[i] != comp[e]){
					odeg[comp[i]]++;
					indeg[comp[e]]++;
				}
			}
		}
		if (ncomps == 1) {
			cout << 0 << endl;
			continue;
		}
		rep(i,0,ncomps){
			if (indeg[i] == 0) n1++;
			if (odeg[i] == 0) n2++;
		}
		cout << max(n1, n2) << endl;
	}
}