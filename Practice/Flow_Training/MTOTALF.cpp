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
const int inf = 1e9;

int cap[128][128] = {{0}};
vi adj[128];
bool vis[128];

int flow(int v, int sink, int bottleneck){
	if (v == sink) return bottleneck;
	for(auto to : adj[v]){
		if (vis[to] || cap[v][to] <= 0) continue;
		vis[to] = true;
		int f = flow(to, sink, min(bottleneck, cap[v][to]));
		if (f) {
			cap[v][to] -= f;
			cap[to][v] += f;
			return f;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		char U, V;
		int u, v;
		int c;
		cin >> U >> V >> c;
		u = (int)U;
		v = (int)V;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cap[u][v] += c;
	}
	int totflow = 0;
	while(true){
		memset(vis, false, 128);
		int f = flow('A', 'Z', inf);
		if (f) {
			totflow += f;
		} else {
			break;
		}
	}
	cout << totflow << endl;
}