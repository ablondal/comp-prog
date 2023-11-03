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

vi G_adj[21];
// vi PG_adj[1<<21];
vi path[1<<21];
int n, m;

int shoot(int curr_mask, int shot){
	curr_mask &= ~(1<<shot); // Monkey can't be where we just shot
	int new_mask = 0;
	rep(from,0,n){
		if (curr_mask & (1<<from)) { // Monkey could be here after the shot
			for(auto to:G_adj[from]) {
				new_mask |= (1<<to); // Monkey can jump here between shots
			}
		}
	}
	return new_mask;
}

void solve(){
	cin >> n >> m;
	if (n == 0 && m == 0) return;

	// Reset variables
	rep(i,0,n) G_adj[i].clear();
	rep(i,0,1<<n) {
		// PG_adj[i].clear();
		path[i].clear();
	}
	// Build Graph
	rep(i,0,m){
		int u, v;
		cin >> u >> v;
		G_adj[u].push_back(v);
		G_adj[v].push_back(u);
	}
	// Do BFS
	queue<int> Q;
	Q.push((1<<n)-1);
	path[(1<<n)-1].push_back(-1);
	while(!Q.empty()){
		int mask = Q.front();
		Q.pop();
		rep(shot,0,n){
			int new_mask = shoot(mask, shot);
			// cout << mask << "->" << new_mask << endl;
			if (path[new_mask].empty()){
				path[new_mask] = path[mask];
				path[new_mask].push_back(shot);
				Q.push(new_mask);
			}
		}
	}
	if (path[0].empty()){
		cout << "Impossible" << endl;
	} else {
		cout << sz(path[0])-1 << ":";
		rep(i,1,sz(path[0])) {
			cout << " " << path[0][i];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	do{
		solve();
	} while (n);
}