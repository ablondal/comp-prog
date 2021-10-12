#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vi> adj(n+1);
		rep(i,0,m){
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vi vis(n+1, 6);
		vi chose;
		queue<int> Q;
		Q.push( ((int)1e8 % n) + 1);
		chose.push_back(((int)1e8 % n) + 1);
		vis[((int)1e8 % n) + 1] = 1;
		while(!Q.empty()){
			int v = Q.front();
			Q.pop();
			for(auto e : adj[v]){
				vis[v] = min(vis[v], vis[e]+1);
			}

			if (vis[v] == 4) {
				vis[v] = 1;
				chose.push_back(v);
			}
			for(auto e : adj[v]){
				if (vis[e]==6){
					Q.push(e);
				}
				vis[e] = min(vis[e], vis[v]+1);
			}
		}
		rep(i,1,n+1){
			// cout << vis[i] << endl;
			if (vis[i] > 2){
				chose.push_back(i);
			}
		}
		cout << chose.size() << endl;
		rep(i,0,sz(chose)){
			cout << chose[i] << " ";
		}
		cout << endl;

	}
	
}