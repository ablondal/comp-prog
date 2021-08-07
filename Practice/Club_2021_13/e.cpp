#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;

vi adj[MAXN];
// int n_adj[MAXN] = {0};
char r[MAXN] = {0};
int maxdep = 0;

int DFS(int v, int p, int dep){
	int taken = 0;
	int minrank = -1;
	for(auto e : adj[v]){
		if (e==p) continue;
		int res = DFS(e, v, dep+1) ;
		if (res & taken){
			minrank = max(minrank, (int)log2(res & taken)+1);
		}
		taken |= res;
	}
	// printf("%d %d\n", v, minrank);
	if (minrank>=0)
		taken |= (1<<minrank)-1;
	taken++;
	// printf("Node %d: %d\n", v, taken);

	r[v] = 'Z'-__builtin_ctz(taken);
	return taken;
	// maxdep = max(maxdep, dep);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	scanf("%d", &n);
	rep(i,0,n-1){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	DFS(1,0,1);

	rep(i,1,n+1){
		printf("%c", r[i]);
		if (i==n) printf("\n");
		else printf(" ");
	}
	// printf("\n");
}