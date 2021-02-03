#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// const int MAXN = 2007;

int n;
vector<vi> adj;
vi st;
// char vis[2507] = {0};


template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

// int dfs(int v, int t, int p){
// 	if (v==t){
// 		st.push_back(t);
// 		return true;
// 	}
// 	st.push_back(v);
// 	for(auto e: adj[v]){
// 		if (e==p) continue;
// 		if (dfs(e, t, v)) return true;
// 	}
// 	st.pop_back();
// 	return false;
// }

int main() {
	while(true){
		scanf("%d", &n);
		adj.resize(n+1);
		if (n==0) break;
		rep(i,0,n) adj[i].clear();
		rep(i,0,n-1){
			int a,b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int l;
		scanf("%d", &l);

		LCA lca(adj);

		rep(i,0,l){
			int a,b;
			scanf("%d%d", &a, &b);
			int d = dist(a,b);


			if (sz(st) % 2 == 1){
				printf("The fleas meet at %d.\n", st[sz(st)/2]);
			}else{
				int A = st[sz(st)/2];
				int B = st[sz(st)/2-1];
				if (B<A) swap(A,B);
				printf("The fleas jump forever between %d and %d.\n", A, B);
			}
		}
	}
}



















