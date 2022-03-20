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

vi adj[200007];
int v[200007] = {0};

void DFS(int V){
	if (v[V]) return;
	v[V] = true;
	for(auto e: adj[V]){
		DFS(e);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	rep(i,0,m){
		int u,vv;
		cin >> u >> vv;
		adj[u].push_back(vv);
		adj[vv].push_back(u);
	}
	DFS(1);
	vi unc;
	rep(i,1,n+1){
		if (!v[i]) unc.push_back(i);
	}
	if (sz(unc)==0){
		cout << "Connected" << endl;
	} else {
		for(auto& e : unc){
			cout << e << endl;
		}
	}
}