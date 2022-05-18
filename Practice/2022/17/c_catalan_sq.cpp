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

struct bigint{
	const ll mod = 1e9;
	vector<ll> L;
	string tostr(){
		stringstream ss;
		for(int i=sz(L)-1; i>=0; --i){
			ss << L[i];
		}
		string s;
		ss >> s;
		return s;
	}
	void carry(){
		ll carry = 0;
		rep(i,0,sz(L)){
			L[i] += carry;
			carry = L[i] / mod;
			L[i] = L[i] % mod;
		}
		while (carry) {
			L.push_back(carry % mod);
			carry /= mod;
		}
	}
	void reduce(){
		while(L.back() == 0) L.pop_back();
	}
	bigint(){}
	bigint(ll i){
		L = {i};
		carry();
		reduce();
	}
	bigint operator*(bigint& a){
		bigint r;
		r.L.resize(sz(a.L) + sz(L), 0);
		rep(i,0,sz(L)){
			rep(j,0,sz(a.L)){
				r.L[i+j] += L[i]*a.L[j];
			}
			r.carry();
		}
		return r;
	}
	bigint operator/(bigint& a){
		bigint r;
		r.L.resize(sz())
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, n;
	cin >> c >> n;
	int intr = 0;
	bool w = true;
	rep(i,0,n){
		int u, v, x;
		cin >> u >> v >> x;
		if (u > intr) w = false;
		intr -= u;
		intr += v;
		if (intr > c) w = false;
		if (x && c-intr > 0) w = false;
	}
	if (intr != 0) w = false;
	cout << (w ? "possible" : "impossible" ) << endl;
}