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
typedef vector<vll> mat;
const ll MAX = 1e5;

int UF[MAX] = {0};
int sz[MAX];
int p[MAX] = {0};
int d[MAX];

int find(int a){
	return (UF[a]==0 ? a : find(UF[a]));
}

int dep(int a){
	if (d[a] != -1) return d[a];
	if (UF[a] == 0) return d[a] = 0;
	return d[a] = dep(UF[a])+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, s;
	cin >> n >> m >> s;
	rep(i,1,n+1){
		sz[i]=1;
		d[i]=-1;
	}
	vector<pair<int, pair<int, int>>> edg;
	rep(i,0,m){
		int u,v,w;
		cin >> u >> v >> w;
		edg.push_back({w,{u,v}});
	}
	sort(all(edg));
	reverse(all(edg));

	for(auto &[w, e]:edg){
		auto [u,v] = e;
		u = find(u);
		v = find(v);
		if (u==v) continue;
		if (sz[u]<sz[v]) swap(u,v);
		UF[v] = u;
		p[v] = w;
		sz[u] += sz[v];
	}

	rep(i,0,s){
		int m = 1e6;
		int l,h;
		cin >> l >> h;
		if (dep(l)<dep(h)) swap(l,h);
		while(dep(l)>dep(h)){
			m = min(m, p[l]);
			l = UF[l];
		}
		while(l != h){
			m = min(m, min(p[l], p[h]));
			l = UF[l];
			h = UF[h];
		}
		cout << m << endl;
	}
}