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

int UF[MX];
int tim[MX];
int find(int x){
	return (UF[x] < 0 ? x : find(UF[x]));
}
void merge(int a, int b){
	a = find(a); b = find(b);
	if (a != b){
		UF[a] = b;
		tim[b] = min(tim[a], tim[b]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vi x(n), y(n);
		map<int, vi> Mx, My;
		rep(i,0,n){
			cin >> x[i] >> y[i] >> tim[i];
			UF[i] = -1;
			Mx[x[i]].push_back(i);
			My[y[i]].push_back(i);
		}
		for(auto& [yy, vv]:My){
			sort(all(vv), [&x](int a, int b){return x[a] < x[b];});
			rep(i,0,sz(vv)-1){
				if (x[vv[i+1]]-x[vv[i]] <= k) merge(vv[i+1], vv[i]);
			}
		}
		for(auto& [xx, vv]:Mx){
			sort(all(vv), [&y](int a, int b){return y[a] < y[b];});
			rep(i,0,sz(vv)-1){
				if (y[vv[i+1]]-y[vv[i]] <= k) merge(vv[i+1], vv[i]);
			}
		}
		vi segs;
		rep(i,0,n){
			if (UF[i] == -1) segs.push_back(tim[i]);//, cout << tim[i] << endl;
		}
		sort(all(segs));
		int j = 0;
		rep(i,0,sz(segs)){
			while(j < sz(segs) && segs[j] <= i) j++;
			if (sz(segs) - j - i - 1 <= 0) {
				cout << i << endl;
				break;
			}
		}
	}
}