#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;

int n, m;
vector<int> adj1[MAXN];
vi adj2[MAXN];
char V[MAXN];
int tin[MAXN] = {0};
int low[MAXN] = {0};
int timer = 1;
set<pair<int, int>> bridges;
int comp[MAXN] = {0};
int parent[MAXN][21] = {{0}};
int dep[MAXN] = {0};

void DFS_dep(int v, int de, int p){
	V[v] = true;
	dep[v] = de;
	parent[v][0] = p;
	for(auto e: adj2[v]){
		if (e==p || V[e]) continue;
		DFS_dep(e, de+1, v);
	}
}

void DFS_bridge(int v, int p){
	V[v] = true;
	low[v] = tin[v] = timer++;
	for(auto &e : adj1[v]){
		if (e==p) continue;
		if (V[e]) {
			low[v] = min(low[v], tin[e]);
		}else{
			DFS_bridge(e,v);
			low[v] = min(low[v], low[e]);
			if (low[e] > tin[v]){
				bridges.insert({v,e});
				bridges.insert({e,v});
			}
		}
	}
}

void DFS_comp(int v, int cc){
	V[v] = true;
	comp[v] = cc;
	for(auto e: adj1[v]){
		if (V[e] || bridges.count({v,e})) continue;
		DFS_comp(e, cc);
	}
}

int LCA(int a, int b){
	if (dep[a]<dep[b]){
		swap(a,b);
	}
	int ddep = dep[a]-dep[b];
	for(int j=19; j>=0; --j){
		if ( (1<<j) <= ddep) {
			ddep -= (1<<j);
			a = parent[a][j];
		}
	}

	if (a==b) return a;

	for(int j=19; j>=0; --j){
		if (parent[a][j] != parent[b][j]){
			a = parent[a][j];
			b = parent[b][j];
		}
	}
	return parent[a][0];
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i,0,m){
		int a,b;
		scanf("%d%d", &a, &b);
		adj1[a].push_back(b);
		adj1[b].push_back(a);
	}
	DFS_bridge(1, -1);
	// for(auto b : bridges){
	// 	printf("brid: %d %d\n", b.first, b.second);
	// }

	memset(V, 0, MAXN);
	timer = 1;
	rep(i,1,n+1){
		if (!V[i]){
			DFS_comp(i,timer);
			timer++;
		}
	}
	// DFS_comp(1,1);
	// rep(i,1,n+1){
	// 	printf("%d %d\n",i, comp[i]);
	// }
	parent[1][0] = 1;
	for(auto [x,y] : bridges){
		// if (comp[x]>comp[y]) swap(x,y);
		// // parent[comp[y]][0] = comp[x];
		// adj2[comp[x]].push_back(comp[y]);
		adj2[comp[y]].push_back(comp[x]);
	}

	memset(V, 0, MAXN);
	DFS_dep(1, 0, 1);

	// rep(i,1,timer){
	// 	printf("dep: %d %d\n", i, dep[i]);
	// }

	for(int j=1; j<20; ++j){
		rep(i,1,timer){
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}

	// rep(i,1,timer){
	// 	printf("%d:",comp[i]);
	// 	rep(j,0,21){
	// 		printf(" %d", parent[comp[i]][j]);
	// 	}
	// 	printf("\n");
	// }

	int k;
	scanf("%d", &k);
	while(k--){
		int si, li;
		scanf("%d%d", &si, &li);
		printf("%d\n", dep[comp[si]] + dep[comp[li]] - 2*dep[LCA(comp[si], comp[li])] );
	}

}