#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// char react[51][51] = {{0}};
vi adj[51];
char V[51] = {0};

void DFS(int v){
	V[v] = true;
	for(int e : adj[v]){
		if (V[e]) continue;
		DFS(e);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	rep(i,0,m){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int tot = 0;
	rep(i,1,n+1){
		if (!V[i]) {
			tot++;
			// cout << i << endl;
			DFS(i);
		}
	}
	ll ans = 1LL << (n - tot);
	cout << ans << endl;
}