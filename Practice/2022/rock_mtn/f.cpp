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

vi adj[307];
int siz[307];
int pol[307];

int DP[307][307][2] = {{{0}}};

void DFS(int v, int p){
	DP[v][siz[v]][1] = pol[v];

	for(auto e : adj[v]){
		if (e==p) continue;
		DFS(e, v);
		for(int i=300; i>=0; --i){
			rep(j,0,i+1){
				DP[v][i][1] = max(
					DP[v][i][1],
					DP[v][j][1] + DP[e][i-j][0]
				);
				DP[v][i][0] = max(
					DP[v][i][0],
					max(
						DP[v][j][0] + DP[e][i-j][1],
						DP[v][j][0] + DP[e][i-j][0]
					)
				);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, S;
	cin >> N >> S;
	rep(i,0,N){
		cin >> siz[i] >> pol[i];
	}
	rep(i,0,N-1){
		int u,v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(0, -1);
	int M = 0;
	rep(i,0,S+1){
		M = max(M, max(DP[0][i][1], DP[0][i][0]));
	}
	cout << M << endl;

}