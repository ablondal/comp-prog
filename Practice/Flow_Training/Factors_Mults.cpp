#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

int M[101];
char vis[101];
vector<int> adj[101];

bool dfs(int v){
	for(int e: adj[v]){
		if (!vis[e]){
			vis[e] = true;
			if (!M[e] || dfs(M[e])){
				M[e] = v;
				return true;
			}
		}
	}
	return false;
}
int L[101];
int R[101];
int main(){
	int n, m, T;
	scanf("%d", &T);
	int t = 1;
	while(t<=T){
		scanf("%d", &n);
		for(int i=1; i<=n; ++i){
			scanf("%d", L+i);
			adj[i].clear();
			L[i] = abs(L[i]);
		}
		scanf("%d", &m);
		for(int i=1; i<=m; ++i){
			M[i] = 0;
			scanf("%d", R+i);
			R[i] = abs(R[i]);
		}
		for(int l=1; l<=n; ++l){
			for(int r=1; r<=m; ++r){
				if (L[l] == 0){
					if (R[r] == 0){
						adj[l].push_back(r);
					}
				}else if (R[r] % L[l] == 0){
					adj[l].push_back(r);
				}
			}
		}
		int tot = 0;
		for(int i=1; i<=n; ++i){
			memset(vis, false, 101);
			tot += dfs(i);
		}
		printf("Case %d: %d\n", t, tot);
		t++;
	}
}













