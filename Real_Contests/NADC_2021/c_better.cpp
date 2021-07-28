#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
int UF[10007];
int find(int x){
	return (UF[x]==x ? x : UF[x] = find(UF[x]));
}
char grid[101][101];
char grid2[10007];

int M[10007];
vi adj[10007];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &m);
	rep(i,0,n*m){
		UF[i] = i;
		M[i] = -1;
	}
	rep(y,0,n) rep(x,0,m){
		scanf(" %c", grid[x][y]);
		grid[y*m+x] = grid[x][y];
		if (x && grid[x-1][y]==grid[x][y]){
			UF[find(y*m+x)] = find(y*m+x-1);
		}
		if (y && grid[x][y-1]==grid[x][y]){
			UF[find(y*m+x)] = find(y*m+x-m);
		}
	}
	int totreg = 0;
	rep(i,0,n*m) totreg += find(i)==i;
	rep(y,0,n) rep(x,0,m){
		if (x && grid[x-1][y]!=grid[x][y]){
			adj[find(y*m+x)].push_back(find(y*m+x-1));
			adj[find(y*m+x-1)].push_back(find(y*m+x));
		}
		if (y && grid[x][y-1]!=grid[x][y]){
			adj[find(y*m+x)].push_back(find(y*m+x-m));
			adj[find(y*m+x-m)].push_back(find(y*m+x));
		}
	}
	rep(i,0,n*m){
		sort(all(adj[i]));
		auto it = unique(all(adj[i]));
		adj[i].resize(it-adj[i].begin());
		if (i%m == 0 || i%m == m-1 || i/m == 0 || i/m == n-1){
			M[find(i)] = -2;
		}
	}
}