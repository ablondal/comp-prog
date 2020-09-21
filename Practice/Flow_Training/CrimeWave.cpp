#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
#define min(a,b) ((a<b)?a:b)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

vpii adj[5007];
char cap[5007][5007] = {{0}};
char vis[5007];

int sz, w, h, b, x, y;

int DFS(int s, int t){
	if (s == t) return 1;
	vis[s] = true;
	for(auto ed : adj[s]){
		int e = ed.first;
		if (cap[s][e]>0 && !vis[e]){
			if (DFS(e, t)){
				cap[e][s]++;
				cap[s][e]--;
				// printf("%d<-%d ", e, s);
				return 1;
			}
		}
	}
	return 0;
}

int flow(int s, int t){
	memset(cap, 0, 5007*5007);
	for(int i=0; i<sz*2+1; ++i){
		for(auto e: adj[i]){
			cap[i][e.first] += e.second;
		}
	}
	int fl = 0;
	while(true){
		memset(vis, false, 5007);
		int f = DFS(s, t);
		// printf("\n");
		if (f){
			fl += f;
		}else{
			break;
		}
	}
	// printf("flow: %d\n", fl);
	return fl;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &w, &h, &b);
		sz = w*h;
		for(int i=0; i<=2*sz; ++i){
			adj[i].clear();
		}
		for(x=0; x<w; ++x){
			for(y=0; y<h; ++y){
				int g = x+y*w;
				adj[g].push_back({g+sz, 1});
				adj[g+sz].push_back({g, 0});
				if (x==0 || y==0 || x==w-1 || y==h-1) adj[g+sz].push_back({2*sz+1, 1});
				if (x) adj[g+sz].push_back({g-1, 1});
				if (y) adj[g+sz].push_back({g-w, 1});
				if (x!=w-1) adj[g+sz].push_back({g+1, 1});
				if (y!=h-1) adj[g+sz].push_back({g+w, 1});
				for(auto e: adj[g+sz]){
					adj[e.first].push_back({g+sz,0});
				}
			}
		}
		for(int i=0; i<b; ++i){
			scanf("%d%d", &x, &y);
			x--;
			y--;
			adj[2*sz].push_back({x+y*w, 1});
		}
		if (flow(2*sz, 2*sz+1) == b){
			printf("possible\n");
		}else{
			printf("not possible\n");
		}
	}
}











