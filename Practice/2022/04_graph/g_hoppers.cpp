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
const int maxn = 5e5+7;

int V[maxn] = {0};
bool bip = true;
vi adj[maxn];

void DFS(int v, int c){
	if (V[v]) return;
	V[v] = c;
	int nc = (c==1?2:1);
	for(auto e : adj[v]){
		if (V[e]==c) bip = false;
		DFS(e,nc);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	rep(i,0,m){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int tot=0;
	rep(i,1,n+1){
		if (!V[i]) {
			tot++;
			DFS(i,1);
		}
	}
	cout << tot-1+bip << endl;
}