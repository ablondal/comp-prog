#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Union-find data structure:
// https://cp-algorithms.com/data_structures/disjoint_set_union.html
// This only uses path-shortening
int UF[1007] = {0};
int find(int v){
	return UF[v]==0 ? v : UF[v] = find(UF[v]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	// Edges connecting already-connected nodes
	// (edges to remove)
	vector<pair<int, int>> close;

	rep(i,0,n-1){
		int u,v;
		cin >> u >> v;
		// Check if u and v are connected
		if (find(u) == find(v)){
			close.push_back({u,v});
		} else {
			// Connect them
			UF[find(u)] = find(v);
		}
	}

	// Now create all needed connections:
	// Connect all roots of connected components
	// in a chain.
	vector<int> cons;
	rep(i,1,n+1){
		if (UF[i]==0){
			cons.push_back(i);
		}
	}

	cout << sz(cons)-1 << endl;

	rep(i,0,sz(cons)-1){
		cout << close[i].first << " " << close[i].second
			<< " " << cons[i] << " " << cons[i+1] << endl;
	}

	return 0;

}