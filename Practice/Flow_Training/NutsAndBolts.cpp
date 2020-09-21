#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int MAXN = 507;

int M[507];
char V[507];
vector<int> adj[507];
int fits[507][507];

bool dfs(int v){
	for(int e : adj[v]){
		if (!V[e]){
			V[e] = true;
			if (M[e] == -1 || dfs(M[e])){
				M[e] = v;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int T;
	scanf("%d", &T);
	int t = 1;
	while(T--){
		int n, b, nuts, bolts;
		scanf("%d%d",&bolts,&nuts);
		for(b=0;b<bolts;b++){
			adj[b].clear();
			for(n=0;n<nuts;n++){
				scanf("%d",&fits[b][n]);
				if (fits[b][n]){
					adj[b].push_back(n);
				}
			}
		}
		for(int i=0; i<507; ++i){
			M[i] = -1;
		}
		int tot = 0;
		for(int i=0; i<bolts; ++i){
			memset(V, false, 507);
			if (dfs(i)){
				tot ++;
			}
		}
		printf("Case %d: ",t);
		t++;
		printf("a maximum of %d nuts and bolts ",tot);
		printf("can be fitted together\n");
	}
}







