#include <cstdio>
#include <cstring>
#include <vector>
#define min(a,b) ((a<b)?a:b)
using namespace std;
const int MAXN = 10007;

vector<int> adj[MAXN];
char vis[MAXN] = {0};
char cap[MAXN][MAXN] = {{0}};

int dfs(int v, int t){
	if (v == t) return 1;
	vis[v] = true;
	// printf("%d ", v);
	for(int e : adj[v]){
		if (!vis[e]){
			if (cap[v][e] && dfs(e, t)){
				cap[v][e]--;
				cap[e][v]++;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int n, m, a, b, s, t;
	vector<bool> ans;
	ans.push_back(false);
	while(scanf("%d%d", &n, &m)){
		if (n==0) break;
		for(int i=1; i<=n; ++i){
			adj[i].clear();
		}
		for(int i=0; i<m; ++i){
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
			cap[a][b] = cap[b][a] = 0;
		}
		for(int i=1; i<=n; ++i){
			for(int e: adj[i]){
				cap[i][e]++;
			}
		}
		scanf("%d%d", &s, &t);
		int tot = 0;
		memset(vis, false, MAXN);
		tot += dfs(s, t);
		memset(vis, false, MAXN);
		tot += dfs(s, t);
		if (tot < 2){
			ans.push_back(0);
		}else{
			ans.push_back(1);
		}
	}
	for(int i=1; i<ans.size(); ++i){
		printf("Case %d: ", i);
		printf((ans[i]? "YES\n" : "NO\n"));
	}
}






















