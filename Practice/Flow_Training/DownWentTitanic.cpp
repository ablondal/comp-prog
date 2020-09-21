#include <iostream>
#include <cstring>
#include <vector>
#define min(a,b) ((a<b)?a:b)
#define pb push_back
using namespace std;
const int INF = 1e7;

vector<int> adj[1807];
int cap[1807][1807] = {{0}};
char vis[1807] = {0};
int X, Y, p, sz, s, t;

int dfs(int v, int t){
	// cout << v << ' ';
	if (v == t) return 1;
	for(int e: adj[v]){
		if(!vis[e] && cap[v][e]){
			vis[e] = true;
			int f = dfs(e, t);
			if (f){
				cap[v][e]--;
				cap[e][v]++;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	string line;
	while(cin >> Y >> X >> p){
		sz = X*Y;
		s = 2*sz + 1;
		t = 2*sz + 2;
		for(int i=0; i<1807; ++i){
			adj[i].clear();
		}

		for(int y = 0; y < Y; ++y){
			cin >> line;
			// cout << line << line.size() << endl;
			for(int x = 0; x < X; ++x){
				// Jump off of square
				int z = x + y*X;
				int Z = z + sz;
				adj[z].pb(Z);
				adj[Z].pb(z);
				cap[z][Z] = 0;
				cap[Z][z] = 0;
				// Onto...
				if (x){
					adj[Z].pb(z-1);
					adj[z-1].pb(Z);
					adj[z].pb(Z-1);
					adj[Z-1].pb(z);

					cap[Z][z-1] = cap[Z-1][z] = INF;
					cap[z-1][Z] = cap[z][Z-1] = 0;
				}
				if (y){
					adj[Z].pb(z-X);
					adj[z-X].pb(Z);
					adj[z].pb(Z-X);
					adj[Z-X].pb(z);

					cap[Z][z-X] = cap[Z-X][z] = INF;
					cap[z-X][Z] = cap[z][Z-X] = 0;
				}
				if (line[x] == '*'){
					adj[s].pb(z);
					cap[s][z] = 1;
					cap[z][Z] = 1;
				}else if (line[x] == '.'){
					cap[z][Z] = 1;
				}else if (line[x] == '@'){
					cap[z][Z] = INF;
				}else if (line[x] == '#'){
					adj[Z].pb(t);
					cap[z][Z] = INF;
					cap[Z][t] = p;
				}
			}
		}

		int tot = 0;
		int flow;
		do{
			flow = dfs(s, t);
			// cout << endl;
			tot += flow;
			memset(vis, false, 1807);
		}while(flow);
		cout << tot << endl;
	}
}























