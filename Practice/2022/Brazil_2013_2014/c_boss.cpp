#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;
typedef vector<vll> mat;
const ll MAX = 507;

vi adj[MAX];
int age[MAX];
char vis[MAX];
int id[MAX];

int dfs(int v){
	if (vis[v]) return 1e6;
	vis[v] = true;
	int m = 1e6;
	for(auto& e : adj[v]){
		m = min(m, dfs(e));
		m = min(age[e], m);
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, I;
	cin >> n >> m >> I;
	rep(i,1,n+1){
		cin >> age[i];
		id[i] = i;
	}
	rep(i,0,m){
		int u,v;
		cin >> u >> v;
		adj[v].push_back(u);
	}
	rep(i,0,I){
		char ins;
		cin >> ins;
		if (ins == 'T'){
			int a, b;
			cin >> a >> b;
			swap(age[id[a]], age[id[b]]);
			swap(id[a], id[b]);
		} else {
			int e;
			cin >> e;
			e = id[e];
			memset(vis, 0, MAX);
			int d = dfs(e);
			if (d == 1e6){
				cout << "*" << endl;
			} else {
				cout << d << endl;
			}
			// cout << dfs(e) << endl;
		}
	}
}