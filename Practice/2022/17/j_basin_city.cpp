#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define minim(a, b) a = min(a, b)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;
const int MX = 100;

vi adj[MX];
bool vis[MX] = {0};
int n, k;

bool ff(int ch){
	if (ch >= k) return true;
	int M = 5;
	int i = -1;
	rep(j,1,n+1){
		if (vis[j]) continue;
		int a = count_if(all(adj[j]), [](int b){return !vis[b];});
		if (a<M) {
			M = a;
			i = j;
		}
	}
	if (i==-1) return false;
	vi nb;
	rep(j,0,sz(adj[i])){
		if (!vis[adj[i][j]]){
			vis[adj[i][j]] = true;
			nb.push_back(adj[i][j]);
		}
	}
	vis[i] = true;
	if (ff(ch+1)) return true;
	vis[i] = false;
	for(auto b:nb) vis[b] = false;

	rep(k,0,sz(nb)){
		rep(l,k+1,sz(nb)){
			vi nbds;
			for(auto b:adj[nb[k]]) if (!vis[b]) {nbds.push_back(b); vis[b] = true;}
			for(auto b:adj[nb[l]]) if (!vis[b]) {nbds.push_back(b); vis[b] = true;}
			if (vis[nb[k]] == false && vis[nb[l]] == false){
				vis[nb[k]] = vis[nb[l]] = true;
				if (ff(ch+2)) return true;
				vis[nb[k]] = vis[nb[l]] = false;
			}
			for(auto b:nbds) vis[b] = false;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> n;
	if (5*k <= n){
		cout << "possible" << endl;
		exit(0);
	}
	rep(i,1,n+1){
		int d;
		cin >> d;
		rep(j,0,d){
			int b;
			cin >> b;
			adj[i].push_back(b);
			// adj[i][b] = true;
		}
	}
	if (ff(0)) {
		cout << "possible" << endl;
	} else {
		cout << "impossible" << endl;
	}

	
}