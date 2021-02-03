#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 2007;

vi adj[MAXN], radj[MAXN];
char vis[MAXN];
vi ord;
int nv;

void dfs1(int v){
	vis[v] = true;
	for(auto e:adj[v]){
		if (!vis[e]){
			dfs1(e);
		}
	}
	ord.push_back(v);
}

void dfs2(int v){
	vis[v] = true;
	nv++;
	for(auto e:radj[v]){
		if (!vis[e]){
			dfs2(e);
		}
	}
}

int main() {

	while(true){
		int n, m;
		scanf("%d%d", &n, &m);
		if (n==0 && m==0) break;
		rep(i,0,n+1){
			adj[i].clear();
			radj[i].clear();
		}
		memset(vis, 0, 2007);
		rep(i,0,m){
			int v,w,p;
			scanf("%d%d%d", &v, &w, &p);
			adj[v].push_back(w);
			radj[w].push_back(v);
			if (p==2){
				adj[w].push_back(v);
				radj[v].push_back(w);
			}
		}
		ord.clear();
		nv = 0;
		rep(i,1,n+1){
			if (!vis[i])
				dfs1(i);
		}
		memset(vis, 0, 2007);
		dfs2(ord[n-1]);
		// printf("%d\n", nv);
		if (nv == n){
			printf("1\n");
		}else printf("0\n");
	}
}



















