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

vi adj[50];
char vis[50] = {0};
char v2[50];
int vnum = 0;
int n;

bool reachable(int v){
	rep(i,0,n) v2[i] = 0;
	queue<int> q;
	q.push(v);
	v2[v] = 1;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(auto e : adj[t]) {
			if (e == 0 || (!vis[e] && !v2[e]) ) {
				v2[e] = 1;
				q.push(e);
			}
		}
	}
	if (!v2[0]) return 0;
	rep(i,1,n) if (!(v2[i] | vis[i])) return 0;
	return 1;
}

ll hcyc(int v){
	// if (!reachable(v)) return 0;
	vis[v] = 1;
	vnum++;
	ll tot = 0;
	for(auto e : adj[v]){
		if (e==0 && vnum==n){
			tot += 1;
		}
		if (!vis[e]) {
			tot += hcyc(e);
		}
	}

	vis[v] = 0;
	vnum--;
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep (i,0,(n/2)*3) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << hcyc(0) / 2 << endl;
}