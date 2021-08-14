#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi adj[107];
int M[107] = {0};
char V[107] = {0};

bool DFS(int v){
	for(auto e : adj[v]){
		if (V[e]) continue;
		V[e] = true;
		if (M[e]==-1 || DFS(M[e])) {
			M[e] = v;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int cas = 0;
	while(cas < t){
		cas++;
		rep(i,0,107){
			M[i] = -1;
			adj[i].clear();
		}
		int n;
		cin >> n;
		vector<ll> a(n);
		rep(i,0,n) cin >> a[i];
		int m;
		cin >> m;
		vector<ll> b(m);
		rep(i,0,m) cin >> b[i];
		rep(i,0,n) rep(j,0,m){
			if (b[j] == 0 || (a[i]!=0 && b[j] % a[i] == 0) ){
				adj[i].push_back(j);
			}
		}
		int tot = 0;
		rep(i,0,n){
			memset(V, false, 107);
			if (DFS(i)) {
				tot++;
			}
		}
		cout << "Case " << cas << ": " << tot << endl;

	}
}