#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define min(a,b) ((a<b)?a:b)
using namespace std;
const int INF = 1e9;

vector<int> adj[107];
int cap[107][107] = {{0}};
char vis[107] = {0};
int M, W;

int dfs(int v, int minf){
	if (v == M){
		return minf;
	}
	// printf("%d ", v);
	vis[v] = true;
	for(int e: adj[v]){
		if (!vis[e] && cap[v][e]){
			int f = dfs(e, min(minf, cap[v][e]) );
			if (f) {
				cap[v][e] -= f;
				cap[e][v] += f;
				return f;
			}
		}
	}
	return 0;
}

int a, b, c;
int main(){
	scanf("%d%d", &M, &W);
	while(M!=0){
		for(int i=0; i<107; ++i){
			adj[i].clear();
		}
		for(int i=2; i<M; ++i){
			scanf("%d%d", &a,&b);
			adj[a].push_back(a+M);
			adj[a+M].push_back(a);
			cap[a][a+M] = b;
			cap[a+M][a] = 0;
		}
		for(int i=0; i<W; ++i){
			scanf("%d%d%d", &a, &b, &c);
			adj[a+M].push_back(b);
			adj[b].push_back(a+M);
			adj[b+M].push_back(a);
			adj[a].push_back(b+M);
			cap[a+M][b] = c;
			cap[b+M][a] = c;
			cap[a][b+M] = 0;
			cap[b][a+M] = 0;
		}
		int tot = 0;
		int flow;
		do{
			flow = dfs(M+1, INF);
			// printf("\n");
			tot+=flow;
			memset(vis, false, 107);
		}while(flow);

		printf("%d\n", tot);
		scanf("%d%d", &M, &W);
	}
}


















