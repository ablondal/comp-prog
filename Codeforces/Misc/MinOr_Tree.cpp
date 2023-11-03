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
const int MX = 2e5+7;

vector<tuple<int, int, int>> E;
int UF[MX];
int find(int x){
	return (UF[x] == -1 ? x : UF[x] = find(UF[x]));
}
bool merge(int a, int b){
	a = find(a); b = find(b);
	if (a==b) return 0;
	UF[a] = b;
	return 1;
}
int n, m;

bool works(int namask){
	rep(i,1,n+1) UF[i] = -1;
	int ct = 0;
	for(auto [u, v, w] : E){
		if (w & namask) continue;
		else {
			ct += merge(u, v);
		}
	}
	// cout << namask << ct << endl;
	if (ct == n-1) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		E.clear();
		rep(i,0,m){
			int u, v, w;
			cin >> u >> v >> w;
			E.push_back({u, v, w});
		}
		int res = 0;
		int bm = 0;
		for(int m = 31; m >=0; m--){
			if (works(bm | (1<<m))){
				bm |= (1<<m);
			} else {
				res |= (1<<m);
			}
		}
		cout << res << endl;
	}
}