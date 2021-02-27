#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef unordered_map<int, int> umii;
const int MAXN = 1e5+7;
typedef struct _node{
	umii* c_map = NULL;
	int dominating = 0;
	ll sum_dom = 0;
} node;

// int tin[MAXN], tout[MAXN], order[MAXN];
vi adj[MAXN];
int c[MAXN];
ll sumdom[MAXN];

node DFS(int v, int p){
	node big;
	node small;
	big.c_map = new umii;
	(*big.c_map)[c[v]] = 1;
	big.dominating = 1;
	big.sum_dom = c[v];
	for(auto e : adj[v]){
		if (e == p) continue;
		small = DFS(e, v);
		if (big.c_map->size() < small.c_map->size()) {
			swap(big, small);
		}
		for(auto el : (*small.c_map) ){
			int& a = (*big.c_map)[el.first];
			a += el.second;
			if (a == big.dominating){
				big.sum_dom += el.first;
			} else if (a > big.dominating){
				big.dominating = a;
				big.sum_dom = el.first;
			}
		}
		free(small.c_map);
		small.c_map = NULL;
	}
	sumdom[v] = big.sum_dom;
	return big;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> c[i];
	}
	rep(i,0,n-1){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	DFS(1,0);
	rep(i,1,n+1){
		cout << (i==1 ? "" : " ") << sumdom[i];
	}
	cout << endl;
}