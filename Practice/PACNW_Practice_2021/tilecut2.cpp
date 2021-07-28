#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

short cap[1807][1807] = {{0}};
char V[1807];
vi adj[1807];

char grid[30][30];

int nei[4][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};

int DFS(int v, int t){
	if (v==t) return 1;
	for(auto e: adj[v]){
		if (V[e] || !cap[v][e]) continue;
		V[e] = true;
		// if (!cap[v][e]) continue;
		if (DFS(e, t)){
			cap[v][e]--;
			cap[e][v]++;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi ans;
	while(cin.peek() != EOF){
		string s;
		int n, m;
		n = 0;
		do{
			if (!getline(cin, s)) break;
			if (sz(s)>0) {
				rep(i,0,sz(s)){
					grid[n][i] = (s[i]=='W' ? 0 : (s[i]=='I' ? 1 : 2));
				}
				m = sz(s);
				n++;
			}
		}while(sz(s)>0);

		// printf("%d %d\n", n, m);

		memset(cap, 0, 1807*1807);
		rep(i,0,1807) adj[i].clear();

		rep(i, 0, n*m){
			int x = i/m;
			int y = i%m;
			adj[i].push_back(i+900);
			cap[i][i+900] = 1;
			if (grid[i/m][i%m] == 0){
				adj[1801].push_back(i);
				cap[1801][i] = 1;
			}else if(grid[x][y] == 2){
				adj[i+900].push_back(1802);
				cap[i+900][1802] = 1;
			}
			for(auto nn: nei){
				int nx = x + nn[0];
				int ny = y + nn[1];
				if (nx>=0 && nx<n && ny>=0 && ny<m){
					if ( (grid[x][y]+1 == grid[nx][ny]) ){
						adj[i+900].push_back(nx*m + ny);
						adj[nx*m + ny].push_back(i+900);
						cap[i+900][nx*m + ny] = 1;
						// printf("from %d,%d to %d,%d\n", x, y, nx, ny);
					}
				}
			}
		}

		int f;
		int tot = 0;
		do{
			memset(V, 0, 1807);
			tot += f = DFS(1801, 1802);
		}while(f!=0);
		ans.push_back(tot);
		// printf("%d\n", tot);
	}
	for(auto a : ans){
		cout << a << endl;
	}
}

/*
WIIW
NNNN
IINN
WWWI

NINWN
INIWI
WWWIW
NNNNN
IWINN
*/