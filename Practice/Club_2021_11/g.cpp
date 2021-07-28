#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9;

vi adj[200007];
char V[200007] = {0};

int DFS(int v, int t){
	// if (adj[v].size()>2) return 2;

	if (v==t) return 1;
	V[v] = true;
	int totret = 0;
	
	for(auto e : adj[v]){
		if (V[e]) continue;
		int ret = DFS(e, t);
		totret += ret;
	}
	// if (v==t) totret = max(totret, 1);
	return totret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<char>> grid(n, vector<char>(m));
	int s, t;
	rep(i,0,n){
		rep(j,0,m){
			scanf(" %c", &grid[i][j]);
			if (grid[i][j]!='#'){
				if (j && grid[i][j-1]!='#'){
					adj[i*m + j].push_back(i*m+j-1);
					adj[i*m+j-1].push_back(i*m + j);
				}
				if (i && grid[i-1][j]!='#'){
					adj[i*m + j].push_back(i*m+j-m);
					adj[i*m+j-m].push_back(i*m + j);
				}
			}
			if (grid[i][j]=='1') s = i*m+j;
			else if (grid[i][j]=='2') t = i*m+j;
		}
	}
	bool works = false;
	rep(i,0,n){
		rep(j,0,m){
			if (grid[i][j]!='#' && adj[i*m+j].size()>2){
				works = true;
			}
		}
	}
	if (DFS(s,t)>1) works = true;
	if (works){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}