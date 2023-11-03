#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e4+7;

vi adj[MX];
int a[MX] = {0};
int b[MX] = {0};

int M = 1;
bool done = true;

void dfs(int v, int p, int lasta){
	if (p == 0) {
		a[v] = M++;
		b[v] = M++;
		if (sz(adj[v]) == 1) {
			int e = adj[v][0];
			a[e] = b[v];
			// b[e] = b[v];
			dfs(e, v, a[v]);
		} else {
			bool w = true;
			for(auto e : adj[v]){
				if (w) {
					a[e] = a[v];
					w = false;
				} else {
					a[e] = b[v];
				}
				dfs(e, v, -1);
			}
		}
		return;
	} else if (lasta != -1) {
		b[v] = lasta;
	} else {
		b[v] = M++;
	}
	for(auto e : adj[v]){
		if (e == p) continue;
		a[e] = b[v];
		dfs(e, v, -1);
		// done = false;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	rep(i,0,n-1){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, -1);
	rep(i,1,n+1){
		cout << a[i] << " " << b[i] << endl;
	}
}