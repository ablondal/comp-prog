#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e4+7;

int M[MAXN];
int M2[MAXN];
char V[MAXN];
char V2[MAXN];
vector<pii> adj[MAXN];

bool DFS(int v, int md){
	if (V2[v]) return false;
	V2[v] = true;
	for(auto [e, c] : adj[v]){
		if (!V[e] && c<=md){
			V[e] = true;
			if (M[e]==-1 || DFS(M[e], md)) {
				M[e] = v;
				return true;
			}
		}
	}
	return false;
}

// bool dfs(int v){
// 	for(int e: adj[v]){
// 		if (!vis[e]){
// 			vis[e] = true;
// 			if (!M[e] || dfs(M[e])){
// 				M[e] = v;
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

bool test(int md, int n, int m){
	rep(i,1,n+1) M[i] = -1, M2[i] = 0;
	int oltot = 0;
	int newtot = 0;
	while(true){
		newtot = 0;
		memset(V, false, MAXN);
		memset(V2, false, MAXN);
		rep(i,1,n+1){
			if (!M2[i]){
				M2[i] = DFS(i,md);
				newtot += M2[i];
			}
		}
		if (newtot==0) break;
		oltot += newtot;
	}
	
	return oltot == n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int hi = 0;
	rep(i,0,m){
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({v, d});
		hi = max(hi, d+1);
	}
	int hihi = hi;
	int lo = 0;
	while(hi-lo>1){
		int md = (hi+lo)>>1;
		// cout << md << " " << test(md, n, m) << endl;
		if (test(md, n, m)) hi = md;
		else lo = md;
	}
	if (hi == hihi) hi = -1;
	cout << hi << endl;
}