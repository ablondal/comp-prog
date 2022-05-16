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

vi adj[(1<<16)];

int vis[(1<<16)] = {0};
int p[(1<<16)] = {0};
int n;

bool dfs(int v, int i){
	if (i == (1<<n)-1) {
		return true;
	}
	rep(d,0,2){
		if (vis[adj[v][d]] == 1) {
			vis[adj[v][d]] = 0;
			bool f = dfs(adj[v][d], i+1);
			vis[adj[v][d]] = 1;
			if (f) {
				p[v] = d;
				return true;
			} else {
				return false;
			}
		}
	}
	rep(d,0,2){
		if (vis[adj[v][d]] == 2) {
			vis[adj[v][d]] = 0;
			bool f = dfs(adj[v][d], i+1);
			vis[adj[v][d]] = 1;
			if (f) {
				p[v] = d;
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int M = (1<<n) - 1;
	rep(i,0,(1<<n)){
		int j = (i<<1) & M;
		adj[i].push_back(j);
		adj[i].push_back(j+1);
		vis[i] = 2;
		p[i] = -1;
	}
	vis[0] = 0;
	dfs(0, 0);
	rep(i,0,n) cout << '0';
	int v = 0;
	while(p[v] != -1){
		cout << p[v];
		v = ((v<<1) & M) + p[v];
	}
	cout << endl;
	// cout << dfs(0, 0) << endl;
}