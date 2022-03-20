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
const ll MAX = 507;

set<vi> V;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int L, C;
	cin >> L >> C;
	vector<vi> M(L, vi(C, 0));
	rep(i,0,L){
		rep(j,0,C){
			cin >> M[i][j];
			M[i][j]--;
		}
	}
	vector<int> r, c;
	rep(i,0,L){
		c.push_back(M[i][0] / C);
	}
	rep(i,0,C){
		r.push_back(M[0][i] % C);
	}
	int g = true;
	rep(i,0,L){
		vi a(C);
		rep(j,0,C) a[j] = M[i][j]%C;
		if (a!=r) g = false;
	}
	rep(i,0,C){
		vi a(L);
		rep(j,0,L) a[j] = M[j][i]/C;
		if (a!=c) g = false;
	}
	if (!g) {
		cout << '*' << endl;
		return 0;
	}
	int tot = 0;
	rep(i,0,C){
		while (r[i] != i){
			swap(r[i], r[r[i]]);
			tot++;
		}
	}
	rep(i,0,L){
		while(c[i] != i){
			swap(c[i], c[c[i]]);
			tot++;
		}
	}

	cout << tot << endl;
	// cout << (g ? 1 : '*') << endl;
	
}