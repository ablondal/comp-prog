#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MX = 1e5+7;

int UF[MX], to[MX], vis[MX], dep[MX];
vi adj[MX];
int find(int x) {return UF[x] == 0 ? x : UF[x] = find(UF[x]);}

int get_dep(int v){
	if (dep[v]) return dep[v];
	if (to[v] == 0) return 1;
	return dep[v] = get_dep(to[v])+1;
}

void solve(){
	int n;
	scanf("%d", &n);
	rep(i,1,n+1){
		UF[i] = to[i] = vis[i] = dep[i] = 0;
		adj[i].clear();
	}
	rep(i,0,n-1){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<pair<int, int>> nds(n);
	rep(i,0,n){
		scanf("%d", &nds[i].first);
		nds[i].second = i+1;
	}
	sort(all(nds));
	rep(i,0,n){
		int j = nds[i].second;
		vis[j] = true;
		rep(k,0,sz(adj[j])){
			int e = adj[j][k];
			if (vis[e]) {
				e = find(e);
				to[e] = j;
				UF[e] = j;
			}
		}
	}
	rep(i,1,n+1){
		printf("%d\n", get_dep(i));
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
}