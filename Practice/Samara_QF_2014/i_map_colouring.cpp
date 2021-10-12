#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll M = 1000000;
unordered_set<ll> edges;

int UF[1007] = {0};
int find(int v){
	return (UF[v]==0) ? v : UF[v] = find(UF[v]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	edges.reserve(n*n);
	rep(i,1,n+1){
		rep(j,i+1,n+1){
			edges.insert(i*M + j);
		}
	}
	vector<pair<int, int>> edg2(m);
	rep(i,0,m){
		int u, v;
		cin >> u >> v;
		if (v < u) swap(u, v);
		edges.erase(u*M + v);
		edg2[i] = {u, v};
	}
	for(auto edg : edges){
		int a = find(edg % M);
		int b = find(edg / M);
		if (a != b){
			UF[a] = b;
		}
	}
	bool w = true;
	for(auto edg : edg2){
		if (find(edg.first) == find(edg.second)) {
			w = false;
			break;
		}
	}
	int num_comps = 0;
	vi color(n+1, 0);
	rep(i,1,n+1){
		if (UF[i]==0){
			num_comps++;
			color[i] = num_comps;
		}
	}
	if (!w || num_comps > k) {
		cout << -1 << endl;
	} else {
		rep(i,1,n+1){
			if (UF[i] != 0) {
				color[i] = color[find(i)];
			}
			cout << color[i] << " ";
		}
		cout << endl;

	}

}