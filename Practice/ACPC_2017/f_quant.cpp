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

// int rc1[1007][1007] = {{0}};
// int rc2[1007][1007] = {{0}};

void populate(vector<vi>& rc, vector<vi>& adj, int N) {
	vi inct(N+1, 0);
	for(int i=1; i<N+1; ++i){
		for(auto e : adj[i]){
			inct[e]++;
		}
	}
	vi nxts;
	rc[1][0] = 1;
	rep(i,1,N+1){
		if (inct[i] == 0){
			nxts.push_back(i);
		}
		// cout << inct[i] << " ";
	}
	while(!nxts.empty()){
		int v = nxts.back();
		nxts.pop_back();
		for(auto e : adj[v]){
			inct[e]--;
			if (inct[e] == 0) {
				nxts.push_back(e);
			}
			rep(j,0,1006){
				if (rc[v][j]) {
					rc[e][j+1] = 1;
				}
			}
		}
		// cout << v << ": ";
		// rep(j,0,10){
		// 	cout << rc[v][j] << " ";
		// }
		// cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n1, n2, m1, m2;
	cin >> n1 >> n2 >> m1 >> m2;
	vector<vi> rc1(n1+1, vi(1007, 0));
	vector<vi> rc2(n2+1, vi(1007, 0));

	vector<vi> adj1(n1+1), adj2(n2+1);

	rep(i,0,m1){
		int u,v;
		cin >> u >> v;
		adj1[u].push_back(v);
	}
	rep(i,0,m2){
		int u,v;
		cin >> u >> v;
		adj2[u].push_back(v);
	}

	populate(rc1, adj1, n1);
	// cout << endl;
	populate(rc2, adj2, n2);

	int q;
	cin >> q;
	while(q--){
		int qq;
		cin >> qq;
		bool w = false;
		rep(i,0,qq+1){
			if (
				i>=0 && i<=1005 &&
				(qq-i)>=0 && (qq-i)<=1005 &&
				rc1[n1][i] && rc2[n2][qq-i]
			) {
				w = true;
				break;
			}
		}
		if (w) cout << "Yes" << endl;
		else cout << "No" << endl;
	}


}