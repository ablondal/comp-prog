#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll node_mask[400007];
ll n_m[400007];

int range[400007][2];

vi adj[400007];
int out = 0;

int n;

ll t[1600007];
char marked[1600007] = {0};

void DP(int v, int p){
	range[v][0] = out;
	for(auto e: adj[v]){
		if (e==p) continue;
		DP(e, v);
	}
	n_m[out] = node_mask[v];
	range[v][1] = out++;
}

void build(int v, int tl, int tr){
	if (tl == tr) {
		t[v] = n_m[tl];
	} else {
		int tm = (tl + tr) / 2;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = t[v*2] | t[v*2+1];
	}
	// printf("%d %lli\n", v, t[v]);
}

void push(int v){
	if (marked[v]) {
		t[v*2] = t[v*2+1] = t[v];
		marked[v*2] = marked[v*2+1] = true;
		marked[v] = false;
	}
}

void update(int v, int tl, int tr, int l, int r, ll col_m){
	if (l>r)
		return;
	if (l==tl && r == tr){
		t[v] = col_m;
		marked[v] = true;
	} else {
		push(v);
		int tm = (tl + tr) / 2;
		update(v*2, tl, tm, l, min(r, tm), col_m);
		update(v*2+1, tm+1, tr, max(l, tm+1), r, col_m);
		t[v] = t[v*2] | t[v*2+1];
		// printf("%d: %lli\n", v, t[v]);
	}
}

ll get(int v, int tl, int tr, int l, int r){
	if (l>r) {
		return 0;
	}
	if (l == tl && r == tr){
		// printf("%lli\n", t[v]);
		return t[v];
	}
	push(v);
	int tm = (tl + tr) / 2;
	ll a = get(v*2, tl, tm, l, min(r, tm));
	a |= get(v*2+1, tm+1, tr, max(l, tm+1), r);
	// printf("%d: %lli\n", v, a);
	return a;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	rep(i,1,n+1){
		int c;
		scanf("%d", &c);
		node_mask[i] = (1LL << c);
	}
	rep(i,0,n-1){
		int x,y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	DP(1,0);
	build(1, 0, n-1);

	// rep(i,0,n){
	// 	printf("%d %d %d\n",i, range[i][0], range[i][1]);
	// }

	// rep(i,0,out){
	// 	printf("%lli ", n_m[i]);
	// }
	// printf("\n");

	rep(i,0,m){
		int type;
		scanf("%d", &type);
		if (type==1){
			int v, c;
			scanf("%d%d", &v, &c);
			update(1, 0, n-1, range[v][0], range[v][1], 1LL << c );
		}else{
			int v;
			scanf("%d", &v);
			ll mask = get(1, 0, n-1, range[v][0], range[v][1]);
			int num = 0;
			while(mask){
				if (mask & 1) num++;
				mask >>= 1;
			}
			printf("%d\n", num);
		}
	}
	
}














