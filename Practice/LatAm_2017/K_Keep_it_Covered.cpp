#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj;
int adji = 0;

char V[807];
int M[807];

char grid[20][20];
int R, C;

int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void connect(int r, int c){
	adj.push_back(vi());
	for ( auto &[dr, dc] : d ){
		int rr = r+dr;
		int cc = c+dc;
		if (rr>=0 && cc>=0 && rr<R && cc<C){
			adj[adji].push_back(rr+ R*cc);
			if (grid[rr][cc] != 'o'){
				adj[adji].push_back(rr+ R*cc + R*C);
			}
		}
	}
	adji++;
}

int DFS(int v){
	for(auto e : adj[v]){
		if (!V[e]){
			V[e] = 1;
			if (M[e]==-1 || DFS(M[e])){
				M[e] = v;
				return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &R, &C);
	int dots=0, totf=0;
	rep(i,0,R) rep(j,0,C){
		scanf(" %c", &grid[i][j]);
		if (grid[i][j] == 'o'){
			dots++;
			totf++;
		}else{
			totf+=2;
		}
	}
	rep(i,0,R) rep(j,0,C){
		if((i+j) % 2 == 0){
			if(grid[i][j]=='o'){
				connect(i, j);
			}else{
				connect(i, j);
				connect(i, j);
			}
		}
	}
	if (dots % 2 == 1 || sz(adj) != totf/2){
		printf("N\n");
		return 0;
	}
	// printf("%d\n", sz(adj));
	rep(i,0,807) M[i] = -1;
	int mat = 0;
	rep(i,0,sz(adj)){
		memset(V, 0, sizeof(V));
		mat += DFS(i);
	}
	// rep(i,0,807){
	// 	if (M[i]!=-1){
	// 		printf("%d %d\n", i, M[i]);
	// 	}
	// }
	if (mat == totf/2){
		printf("Y\n");
	}else{
		printf("N\n");
	}
}



















