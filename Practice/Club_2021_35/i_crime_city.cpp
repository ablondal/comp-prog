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

map<pair<int, int>, int> MM;
int siz = 0;
vector<pair<int, int>> edgs;

int DFS(int v, int t, vector<vector<int>>& cap, vector<vector<int>>& adj, vector<int>& vis){
	if (v==t) return 1;
	for(auto e : adj[v]){
		if (cap[v][e] && !vis[e]){
			vis[e] = true;
			int f = DFS(e,t,cap,adj,vis);
			if (f) {
				cap[v][e] -= f;
				cap[e][v] += f;
				return f;
			}
		}
	}
	return 0;
}

int do_flow(int s, int t){
	vector<vector<int>> cap(siz, vi(siz, 0));
	vector<vector<int>> adj(siz);
	for(auto e : edgs){
		adj[e.first].push_back(e.second);
		adj[e.second].push_back(e.first);
		cap[e.first][e.second] += 1;
	}
	int flow = 0;
	while(true){
		vector<int> vis(siz, 0);
		int f = DFS(s, t, cap, adj, vis);
		flow += f;
		if (!f) break;
	}
	return flow;
}

int vtex(int x, int y, bool updown){
	y *= (updown ? -1 : 1);
	if (y>x) swap(x,y);
	auto f = MM.find({x,y});
	if (f==MM.end()) {
		MM[{x,y}] = siz++;
	}
	return MM[{x,y}];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		MM.clear();
		edgs.clear();
		int s, a, b;
		cin >> s >> a >> b;
		int sourc = vtex(0, 0, 0);
		int sink = vtex(0, 1, 0);
		rep(x,1,s+1){
			rep(y,1,a+1){
				edgs.push_back({vtex(x,y,0), vtex(x,y,1)});
				edgs.push_back({vtex(x,y,1), vtex(x-1,y,0)});
				edgs.push_back({vtex(x,y,1), vtex(x+1,y,0)});
				edgs.push_back({vtex(x,y,1), vtex(x,y-1,0)});
				edgs.push_back({vtex(x,y,1), vtex(x,y+1,0)});
			}
		}
		rep(x,1,s+1){
			edgs.push_back({vtex(x,0,0), sink});
			edgs.push_back({vtex(x,a,0), sink});
		}
		rep(y,1,a+1){
			edgs.push_back({vtex(0,y,0), sink});
			edgs.push_back({vtex(s,y,0), sink});
		}

		rep(i,0,b){
			int x,y;
			cin >> x >> y;
			edgs.push_back({sourc, vtex(x,y,0)});
		}
		cout << (do_flow(sourc, sink) == b ? "possible" : "not possible") << endl;
	}
}