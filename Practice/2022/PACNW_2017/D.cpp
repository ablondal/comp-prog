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
const int NX = 50007;

map<int, vi> adj[NX];
vector<pair<int, int>> tolaunch[NX];
char mark[NX] = {0};

void killDFS(int v, int p, int c){
	mark[v] = 1;
	for(auto& [c2, vv] : adj[v]){
		for(auto &e: vv){
			if (e != p){
				killDFS(e, v, c2);
			}
		}
	}
	adj[v].clear();
	adj[v][c] = {p};
}

void prepDFS(int v){
	vi tok;
	for(auto& [c, vv] : adj[v]){
		if (sz(vv) > 1){
			for(auto &e: vv){
				tolaunch[v].push_back({e, c});
			}
			tok.push_back(c);
		}
	}
	for(auto &k : tok){
		adj[v].erase(k);
	}
}

void launchDFS(int v){
	for(auto& [e, c] : tolaunch[v]){
		killDFS(e,v,c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n-1){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a][c].push_back(b);
		adj[b][c].push_back(a);
	}
	rep(i,1,n+1){
		prepDFS(i);
	}
	rep(i,1,n+1){
		launchDFS(i);
	}
	vi gd;
	rep(i,1,n+1){
		if (mark[i]==0) gd.push_back(i);
	}
	cout << sz(gd) << endl;
	for(auto& g : gd){
		cout << g << endl;
	}
}