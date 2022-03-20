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

vi adj[10007];
int indeg[10007] = {0};
bool vis[10007] = {0};

int DFS(int v){
	if (vis[v]) return 0;
	vis[v] = true;
	int t = (indeg[v]==0);
	for(auto e : adj[v])
		t += DFS(e);
	return t;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,1,n+1){
		int t;
		cin >> t;
		// cin >> adj[i];
		indeg[t]++;
		adj[i].push_back(t);
		adj[t].push_back(i);
	}
	int spikes = 0;
	rep(i,1,n+1) spikes+=(indeg[i]==0);
	int grps = 0;
	priority_queue<int> Q;
	int tot = 0;
	rep(i,1,n+1){
		if (!vis[i]){
			int sp = DFS(i);
			grps++;
			if (sp > 1) tot += (sp-1);
			// Q.push(DFS(i));
			// grps++;
			// DFS(i);
		}
	}
	if (grps == 1) {
		tot = spikes;
	} else {
		tot += grps;
	}
	// cout << spikes << endl;
	// while(Q.size() > 1){
	// 	int a = Q.top();
	// 	Q.pop();
	// 	int b = Q.top();
	// 	Q.pop();
	// 	tot += 2;
	// 	if (a > 0 && b > 0) {
	// 		Q.push(a+b-2);
	// 	} else if (a > 0) {
	// 		Q.push(a-1);
	// 	} else {
	// 		Q.push(0);
	// 	}
	// }
	// int a = Q.top();
	// tot += (a);
	cout << tot << endl;
	
}