#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

vi adj[407];
int M[407];
bool vis[407];

int DFS(int v){
	for(auto e : adj[v]){
		if (vis[e]) continue;
		vis[e] = 1;
		if (M[e]==-1 || DFS(M[e])){
			M[e] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while(n--){
		rep(i,0,407){
			adj[i].clear();
			M[i] = -1;
		}
		int h, w;
		cin >> h >> w;
		vector<string> grid(h);
		int ct = 0;
		rep(i,0,h){
			cin >> grid[i];
			rep(j,0,w){
				if (grid[i][j] == '*') ct++;
			}
		}

		rep(i,0,h) rep(j,0,w){
			if ( grid[i][j] == '*' && (i+j) % 2 == 0){
				if (i && grid[i-1][j] == '*') {
					adj[i*w + j].push_back((i-1)*w + j);
				}
				if (i<h-1 && grid[i+1][j] == '*'){
					adj[i*w + j].push_back((i+1)*w + j);
				}
				if (j && grid[i][j-1] == '*') {
					adj[i*w+j].push_back(i*w+j-1);
				}
				if (j<w-1 && grid[i][j+1] == '*'){
					adj[i*w+j].push_back(i*w+j+1);
				}
			}
		}
		int totmatch = 0;
		rep(i,0,h) rep(j,0,w){
			if ( grid[i][j] == '*' && (i+j) % 2 == 0){
				memset(vis, false, 407);
				totmatch += DFS(i*w+j);
			}
		}
		cout << ct - totmatch << endl;
	}
}