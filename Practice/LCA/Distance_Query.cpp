#include <vector>
#include <cmath>
#include <cstdio>
#include <utility>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int MAXN = 1e5 + 7;
const int MAXL = 18; // equal to one more than log2(MAXN)
const int INF = 1e9+7; // bigger than maxcost * MAXN

vpii adj[MAXN];
int n, a, b, c, l, timer;
int up[MAXN][MAXL], M[MAXN][MAXL], m[MAXN][MAXL];
int tin[MAXN], tout[MAXN];

void lca_dfs(int v, int p, int cost){
	tin[v] = ++timer;
	up[v][0] = p;
	if (cost > 0){
		M[v][0] = cost;
		m[v][0] = cost;
	}else{
		M[v][0] = 0;
		m[v][0] = INF;
	}
	int u = p;
	for (int i = 1; i <= l; ++i){
		M[v][i] = max(M[v][i-1], M[u][i-1]);
		m[v][i] = min(m[v][i-1], m[u][i-1]);
		u = up[v][i] = up[u][i-1];
	}
	for(auto e : adj[v]){
		if (e.first != p){
			lca_dfs(e.first, v, e.second);
		}
	}
	tout[v] = ++timer;
}

bool isancestor(int u, int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
	if (isancestor(u, v)){
		return u;
	}
	if (isancestor(v, u)){
		return v;
	}
	for(int i=l; i>=0; --i){
		if (!isancestor(up[u][i], v)){
			u = up[u][i];
		}
	}
	return up[u][0];
}

void make_lca(int root){
	timer = 0;
	l = ceil(log2(n));
	lca_dfs(root, root, -1);
}

// Assume u != v
void min_max_lca(int u, int v, int &minC, int &maxC){
	int p = lca(u, v);
	minC = INF;
	maxC = 0;
	if (u != p){
		for(int i=l; i>=0; --i){
			if (!isancestor(up[u][i], p)){
				minC = min(minC, m[u][i]);
				maxC = max(maxC, M[u][i]);
				u = up[u][i];
			}
		}
		minC = min(minC, m[u][0]);
		maxC = max(maxC, M[u][0]);
	}
	if (v != p){
		for(int i=l; i>=0; --i){
			if (!isancestor(up[v][i], p)){
				minC = min(minC, m[v][i]);
				maxC = max(maxC, M[v][i]);
				v = up[v][i];
			}
		}
		minC = min(minC, m[v][0]);
		maxC = max(maxC, M[v][0]);
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n-1; ++i){
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	make_lca(1);

	int q, minC, maxC;
	scanf("%d", &q);
	for(int i=0; i<q; ++i){
		scanf("%d%d", &a, &b);
		min_max_lca(a, b, minC, maxC);
		printf("%d %d\n", minC, maxC);
	}
}











