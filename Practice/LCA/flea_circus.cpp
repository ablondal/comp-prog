#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 5007;

vi adj[5007];
int parent[MAXN][17];
int n;

void DFS_parent(int v, int p){
	parent[v][0] = p;
	for(auto e: adj[v]){
		if (e != p) DFS_parent(e, v);
	}
}

void make_LCA(){
	for(int j=1; (1<<j) < n; ++j){
		rep(i,1,n+1){
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
}

int main() {
	while(true){
		// int n;
		scanf("%d\n", &n);
		if (n==0) break; // Program ends
		rep(i,0,5007){
			adj[i].clear();
		}
		rep(i,0,n-1){
			int a,b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		DFS_parent(1, 1);
		// B
	}
}