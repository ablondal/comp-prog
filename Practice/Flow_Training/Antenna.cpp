#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[401];
int M[401];
char vis[401];

bool dfs(int v){
	// printf("%d\n", v);
	for(auto e: adj[v]){
		if (!vis[e]){
			vis[e] = true;
			if (M[e] == -1 || dfs(M[e]) ){
				M[e] = v;
				return true;
			}
		}
	}
	return false;
}

int T;
int h, w;
char grid[10][40] = {{0}};
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &h, &w);
		int tot = 0;
		for(int y=0; y<h; ++y){
			for(int x=0; x<w; ++x){
				scanf(" %c", &grid[x][y]);
				if (grid[x][y] == '*'){
					adj[x+10*y].clear();
					tot++;
					if (x && grid[x-1][y] == '*'){
						adj[x+10*y].push_back(x-1+10*y);
						adj[x-1+10*y].push_back(x+10*y);
					}
					if (y && grid[x][y-1] == '*'){
						adj[x+10*y].push_back(x+10*y-10);
						adj[x+10*y-10].push_back(x+10*y);
					}
				}
			}
		}
		for(int i=0; i<401; ++i) M[i] = -1;
		for(int y=0; y<h; ++y){
			for(int x=0; x<w; ++x){
				if ( (x+y) & 1 && grid[x][y] == '*'){
					memset(vis, false, 401);
					if (dfs(x+10*y)){
						tot--;
					}
				}
			}
		}
		printf("%d\n", tot);
	}
}









