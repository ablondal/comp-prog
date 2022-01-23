#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
// incomplete

int cap[128][128] = {{0}};
vector<int> adj[128];
bool vis[128];

// Depth-first search
int flow(int curr, int sink, int bottleneck){
	if (curr == sink) {
		return bottleneck;
	}
	for (auto to : adj[curr]){
	// for (int i=0; i<adj[curr].size(); ++i){
	// 	auto to = adj[curr][i];
		if (vis[to]) continue;
		if (cap[curr][to] <= 0) continue;
		vis[to] = true;
		int f = flow(to, sink,
			min(bottleneck, cap[curr][to])
		);
		if (f > 0) {
			cap[curr][to] -= f;
			cap[to][curr] += f;
			return f;
		}
	}
	return 0;
}

int main() {
	// Makes C++ input faster
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		char A, B;
		int a, b, c;
		cin >> A >> B >> c;
		a = (int)A;
		b = (int)B;
		adj[a].push_back(b);
		adj[b].push_back(a);
		cap[a][b] += c;
	}

	int totflow = 0;
	while(true){
		memset(vis, 0, 128);
		int f = flow('A', 'Z', inf);
		totflow += f;
		if (f == 0) break;
	}

	cout << totflow << endl;
}