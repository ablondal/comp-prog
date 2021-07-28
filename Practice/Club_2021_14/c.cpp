#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;

unordered_map<ll, ll> DP;
vi adj[MAXN];
ll M;

ll DFS(int v, int p){
	ll id = v + 1e7*p;
	auto it = DP.find(id);
	if (it != DP.end()) return it->second;
	// cout << "calculating " << v << " " << p << endl;
	ll tot = 1;
	for(auto e : adj[v]){
		if (e == p) continue;
		tot *= (DFS(e, v)+1);
		tot %= M;
	}
	DP[id] = tot;
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n >> M;
	rep(i,0,n-1){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	rep(i,1,n+1){
		cout << DFS(i, 0) << endl;
	}
}