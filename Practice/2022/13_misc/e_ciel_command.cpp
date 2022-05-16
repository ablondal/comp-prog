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
const int MX = 1e5+7;

vi adj[MX];
char res[MX] = {0};
int siz[MX] = {0};

int c_siz(int v, int p){
	siz[v] = 1;
	for(auto &e : adj[v]){
		if (e == p || res[e]) continue;
		siz[v] += c_siz(e, v);
	}
	return siz[v];
}

void calc(int v, char M){
	// Find centroid
	int sp = c_siz(v, -1);
	bool w = true;
	while(w){
		w = false;
		for(auto &e : adj[v]){
			if (res[e] || siz[e] > siz[v]) continue;
			if (siz[e] > sp/2){
				w = true;
				v = e;
				break;
			}
		}
	}

	// Assign and split
	res[v] = M;
	for(auto& e : adj[v]){
		if (!res[e]) calc(e, M+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n-1){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	calc(1, 'A');
	rep(i,1,n+1){
		cout << res[i] << " ";
	}
	cout << endl;
}