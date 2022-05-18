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
const int MX = 507;
int x[MX], y[MX];
int d[MX][MX];
int UF[MX*MX] = {0}, dep[MX*MX] = {0}, p[MX*MX];

int find(int v){
	while(UF[v]>0) v = UF[v];
	return v;
}

void merge(int a, int b, int dis){
	a = find(a);
	b = find(b);
	if (a==b) return;
	if (UF[a] > UF[b]) swap(a,b);
	UF[a] += UF[b];
	UF[b] = a;
	p[b] = dis;
	// cout << "(" << a%MX << "," << a/MX << ") (" << b%MX << "," << b/MX << ") " << dis << endl;
}

int get_dep(int a){
	if (dep[a]) return dep[a];
	if (UF[a]<0) return dep[a] = 1;
	return dep[a] = get_dep(UF[a])+1;
}

int get_min(int a, int b){
	// cout << a << " " << b << endl;
	if (get_dep(b)>get_dep(a)) swap(a,b);
	int m = 1e9;
	while(get_dep(a)>get_dep(b)){
		m = min(m, p[a]);
		a = UF[a];
	}
	// cout << dep[a] << " " << dep[b] << endl;
	while(a != b){
		m = min(m, p[a]);
		m = min(m, p[b]);
		a = UF[a];
		b = UF[b];
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,1,n+1) cin >> x[i] >> y[i];
	rep(i,1,n+1){
		rep(j,i,n+1){
			d[i][j] = d[j][i] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
			UF[i*MX+j] = UF[j*MX+i] = -1;
		}
	}

	vector<pair<int, pair<int, int>>> edges;
	int m;
	cin >> m;
	rep(i,0,m){
		int u, v;
		cin >> u >> v;
		rep(j,1,n+1){
			int md = min(d[j][u], d[j][v]);
			edges.push_back({md, {j*MX+u, j*MX+v}});
			edges.push_back({md, {u*MX+j, v*MX+j}});
		}
	}
	sort(all(edges));
	reverse(all(edges));
	for(auto [dis, uv]:edges){
		auto [u, v] = uv;
		merge(u, v, dis);
	}
	int l;
	cin >> l;
	rep(i,0,l){
		int a, b;
		cin >> a >> b;
		cout << setprecision(10) << sqrt(get_min(a*MX+b, b*MX+a)) << endl;
	}

}