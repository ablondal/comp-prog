#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 5007;
vi adj[MX];

__uint128_t tot, k;
int n;

__uint128_t subct[MX] = {0};

__uint128_t DP[MX][MX] = {{0}};
int s[MX] = {0};

void dfs(int v, int p) {
	DP[v][1] = 1;
	s[v] = 1;
	for(auto e : adj[v]){
		if (e == p) continue;
		dfs(e, v);
		for(int i=s[v]+1; i>0; --i) {
			rep(j,1,s[e]+1) {
				DP[v][i+j] += DP[v][i] * DP[e][j];
				if (DP[v][i+j] > k) DP[v][i+j] = k;
			}
		}
		s[v] += s[e];
	}
	rep(i,1,s[v]+1){
		subct[i] += DP[v][i];
		if (subct[i] > k) subct[i] = k;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	ll K;
	cin >> n >> K;
	k = K;
	rep(i,0,n-1){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	int i = 1;
	for(; i < n+1; i++){
		if (subct[i] >= k) break;
		k -= subct[i];
		// cout << subct[i] << endl;
		// k -= subct[i];
		// if (k <= 0) break;
	}
	cout << (i > n ? -1 : i) << endl;
}