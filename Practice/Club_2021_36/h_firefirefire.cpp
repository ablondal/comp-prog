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

vi adj[1007];
int DP[1007][2] = {{0}};
void DFS(int v, int p){
	// cout << v << endl;
	DP[v][0] = 0;
	DP[v][1] = 1;
	for(auto e : adj[v]){
		if (e == p) continue;
		DFS(e, v);
		DP[v][0] += DP[e][1];
		DP[v][1] += min(DP[e][0], DP[e][1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin >> n){
		if (n==0) break;
		rep(i,1,n+1){
			adj[i].clear();
			int ni;
			cin >> ni;
			while(ni--){
				int v;
				cin >> v;
				adj[i].push_back(v);
			}
		}
		DFS(1,0);
		cout << max(1, min(DP[1][0], DP[1][1])) << endl;
	}
}