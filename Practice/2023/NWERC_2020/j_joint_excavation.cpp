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
const int MAXN = 2e5+7;

vi adj[MAXN];
bool vis[MAXN] = {0};
vi B;
set<int> A;
vector<int> path;

bool DFS(int v){
	vis[v] = true;
	path.push_back(v);
	A.erase(v);
	if (sz(A) == sz(B)) return 1;

	for(auto e : adj[v]){
		if (!vis[e]) {
			if (DFS(e)) {
				return 1;
			}
		}
	}

	B.push_back(path.back());
	path.pop_back();
	if (sz(A) == sz(B)) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, t;
	cin >> c >> t;
	rep(i,0,t){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	rep(i,1,c+1){
		A.insert(i);
	}
	DFS(1);
	// cout << sz(B) << endl;
	cout << sz(path) << " " << sz(A) << endl;
	for(auto p : path) cout << p << " ";
		cout << endl;
	for(auto a : A){
		cout << a << " ";
	}
	cout << endl;
	for(auto b : B){
		cout << b << " ";
	}
	cout << endl;
}