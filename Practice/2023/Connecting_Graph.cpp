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

vector<int> UF, t, s, dep;

pair<int, int> root_time(int x){
	int mx = 0;
	while(UF[x]){
		mx = max(mx, t[x]);
		x = UF[x];
	}
	return {x, mx};
}

void q1(int b, int c, int tt){
	auto [r1, t1] = root_time(b);
	auto [r2, t2] = root_time(c);
	if (r1 != r2) {
		if (s[r1] > s[r2]) swap(r1, r2);
		UF[r1] = r2;
		s[r2] += UF[r1];
		t[r1] = tt;
	}
}

int d(int x){
	if (dep[x] != -1) return dep[x];
	if (UF[x]) return dep[x] = d(UF[x])+1;
	return dep[x] = 0;
}

void q2(int b, int c, int tt){
	int mx = 0;
	if (d(c) > d(b)) {
		swap(b, c);
	}
	while (d(b) > d(c)){
		mx = max(mx, t[b]);
		b = UF[b];
	}
	while (b != c) {
		mx = max(mx, t[b]);
		mx = max(mx, t[c]);
		b = UF[b];
		c = UF[c];
	}
	if (mx < tt) {
		cout << mx << endl;
	} else {
		cout << -1 << endl;
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	n++;
	UF.resize(n, 0);
	t.resize(n, 1e8);
	s.resize(n, 1);
	dep.resize(n, -1);
	vector<tuple<int, int, int>> Qs;
	rep(tt, 1, m+1){
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			q1(b,c,tt);
		} else {
			Qs.push_back({b, c, tt});
		}
	}
	for(auto [b, c, tt]: Qs){
		q2(b, c, tt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}