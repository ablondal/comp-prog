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

vi pi(const vi& s){
	vi p(sz(s));
	rep(i,1,sz(s)){
		int g = p[i-1];
		while(g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

bool match(const vi& s, const vi& pat){
	vi a(all(pat));
	a.push_back(-1);
	for(auto pt : s) a.push_back(pt);
	// a.insert(all(pat));
	vi p = pi(a), res;
	rep(i,sz(p)-sz(s), sz(p))
		if (p[i] == sz(pat)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n), ac(n), b(n), bc(n);
	rep(i,0,n) cin >> a[i];
	rep(i,0,n) cin >> b[i];
	sort(all(a)); sort(all(b));
	rep(i,1,n){
		ac[i] = a[i]-a[i-1];
		bc[i] = b[i]-b[i-1];
	}
	ac[0] = a[0] + 360000 - a[n-1];
	bc[0] = b[0] + 360000 - b[n-1];
	rep(i,0,n){
		bc.push_back(bc[i]);
	}
	auto r = match(bc, ac);
	cout << (r ? "possible" : "impossible") << endl;


}