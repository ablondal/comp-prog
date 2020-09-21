#include <vector>
#include <cstdio>
#include <cstring>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
typedef long long ll;
int h, w;
int grid[100][100];
int mX[101] = {0}, mY[101] = {0};

vector<int> adj[101];
int M[201];
char vis[201];

bool dfs(int v){
	vis[v] = true;
	for (auto e : adj[v]){
		if (!vis[e]){
			vis[e] = true;
			if( M[e] == -1 || dfs(M[e]) ){
				M[e] = v;
				return true;
			}
		}
	}
	return false;
}

int main(){
	ll tot = 0;
	ll tot_min = 0;
	scanf("%d%d", &h, &w);
	for(int y=0; y<h; ++y){
		for(int x=0; x<w; ++x){
			scanf("%d", &grid[x][y]);
			tot += grid[x][y];
			if (grid[x][y]) tot_min++;
			mX[x] = max(mX[x], grid[x][y]);
			mY[y] = max(mY[y], grid[x][y]);
		}
	}
	// set<int> vals;
	// for(int i=0; i<h; ++i) vals.insert(mY[i]);
	// for(int i=0; i<w; ++i) vals.insert(mX[i]);

	for(int x=0; x<w; ++x){
		for(int y=0; y<h; ++y){
			if (grid[x][y] && mX[x] == mY[y]){
				adj[x].push_back(y+100);
			}
		}
	}

	for(int i=0; i<201; ++i){
		M[i] = -1;
	}

	for(int x=0; x<w; ++x){
		memset(vis, false, 201);
		dfs(x);
	}

	for(int x=0; x<w; ++x){
		if (mX[x] != 0)
			tot_min += mX[x]-1;
	}
	for(int y=0; y<h; ++y){
		if (M[y+100] == -1 && mY[y] != 0){
			tot_min += mY[y]-1;
		}
		// printf("M[%d] = %d\n", y, M[y+100]);
	}
	printf("%lli\n", tot-tot_min);
}






