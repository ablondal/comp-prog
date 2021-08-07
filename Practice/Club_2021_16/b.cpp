#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 2e5+7;

struct edg{
	int dest;
	int c;
	int d;
	edg(int a, int c, int d):dest(a), c(c), d(d){}
};

vector<edg> adj[MAXN];
ll a, b;

void DFS(int v, int p, int n){
	if (n) a++;
	else b++;
	for(auto e : adj[v]){
		if (e.dest==p) continue;
		DFS(e.dest, v, n ^ 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	a = b = 0;
	int n;
	cin >> n;
	rep(i,0,n-1){
		int u,v,c,d;
		cin >> u >> v >> c >> d;
		adj[u].emplace_back(v, c, d);
		adj[v].emplace_back(u, c, d);
	}
	DFS(1, 0, 0);
	cout << a*b-n+1 << endl;
}