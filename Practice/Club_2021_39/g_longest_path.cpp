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

vi adj[100007];
int DP[100007];

int dfs(int v){
	if (DP[v] != -1) return DP[v];
	DP[v] = 0;
	for(auto e : adj[v]){
		DP[v] = max(dfs(e)+1, DP[v]);
	}
	return DP[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	rep(i,0,m){
		int u,v;
		cin >> u >> v;
		adj[v].push_back(u);
	}
	rep(i,1,n+1) DP[i]=-1;
	int M = 0;
	rep(i,1,n+1){
		M = max(M, dfs(i));
	}
	cout << M << endl;
}