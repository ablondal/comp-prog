#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bitset<507> pred[507];
vi adj[507];
int k, n;
int vis[507] = {0};

void DFS(int v, int p){
	int ct = pred[v].count();
	pred[v] |= pred[p];
	if (pred[v].count() != ct || !vis[v]){
		vis[v] = true;
		for(auto e : adj[v]){
			DFS(e, v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int t;
	cin >> n >> k;
	rep(i,1,n+1){
		int a;
		cin >> a;
		rep(j,0,a){
			int b;
			cin >> b;
			adj[i].push_back(b);
		}
		pred[i][i] = true;
		adj[i].push_back(i);
	}
	rep(i,1,n+1){
		DFS(i, 0);
	}
	rep(i,1,n+1){
		if (pred[i].count() > k){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}
}