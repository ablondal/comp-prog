#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
using namespace std;
typedef vector<pair<int, int> > vpii;
typedef vector<int> vi;

const int INF = 1e9;

vpii adj[201];
int cap[201][201];
char vis[201];
int n;

int DFS(int n, int t, int mincap){
	// printf("%d ", n);
	if (n == t){
		return mincap;
	}
	vis[n] = true;
	for(auto e : adj[n]){
		if (!vis[e.first] && cap[n][e.first] > 0){
			int f = DFS(e.first, t, min(mincap, cap[n][e.first]));
			if (f){
				cap[n][e.first] -= f;
				cap[e.first][n] += f;
				return f;
			}
		}f
	}
	return 0;
}

int flow(int n, int s, int t){
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cap[i][j] = 0;
		}
		for(auto e : adj[i]){
			cap[i][e.first] = e.second;
		}
	}
	int flow = 0;
	int f;
	while(true){
		memset(vis, false, n);
		f = DFS(s, t, INF);
		if (f) {
			flow += f;
		}else{
			break;
		}
	}
	// printf("\nGot flow of %d from %d to %d\n", flow, s, t);
	return flow;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int x, y, ni, mi;
		double d;
		int n_peng = 0;

		scanf("%d %lf", &n, &d);
		vector<int> X(n+1), Y(n+1);
		d *= d;
		adj[0].clear();
		for(int i=1; i<=n; ++i){
			adj[i].clear();
			adj[i+n].clear();
			scanf("%d %d %d %d", &x, &y, &ni, &mi);
			X[i] = (x);
			Y[i] = (y);
			adj[i].push_back({i+n, mi});
			adj[0].push_back({i, ni});
			n_peng += ni;
			for(int j=1; j<i; ++j){
				// printf("%d <= %lf ?\n", (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]), d);
				if ( (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]) <= d ){
					adj[i+n].push_back({j, INF});
					adj[j+n].push_back({i, INF});
					adj[i].push_back({j+n, 0});
					adj[j].push_back({i+n, 0});
					// printf("%d and %d are close\n", i, j);
				}
			}
		}

		vi works;
		for(int i=1; i<=n; ++i){
			if (flow(2*n+1, 0, i) == n_peng){
				works.push_back(i-1);
			}
		}
		if(works.size()){
			for(int i=0; i<works.size(); ++i){
				if (i) printf(" ");
				printf("%d", works[i]);
			}
			printf("\n");
		}else{
			printf("-1\n");
		}

	}
}













