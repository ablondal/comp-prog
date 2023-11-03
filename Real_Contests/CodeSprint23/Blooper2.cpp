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
typedef long double ld;

// Calculates the smallest n such that l^(p^n) < x
ll f_inv(ld l, ld p, ld x){
	double pn = logl(x) / logl(l);
	double n = logl(pn) / logl(p);
	return max(0LL, (ll)ceil(n));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, L;
	ld P;
	cin >> N >> L >> P;
	vector<ld> s(N);
	long double hi = 1, lo = 1;
	rep(i,0,N){
		cin >> s[i];
		hi = max(hi, s[i]);
	}
	// ll n = f_inv()
	int rrr = 0;
	while(hi-lo > (ld)1e-13 && rrr < 40){
		rrr++;
		ld md = lo + (hi-lo)*0.5;
		ll tot = 0;
		rep(i,0,N){
			tot += f_inv(s[i], P, md);
		}
		if (tot > L) {
			lo = md;
		} else {
			hi = md;
		}
		if (tot == L) {
			hi = lo = md;
			break;
		}
		// cout << tot << " " << md << endl;
	}
	priority_queue<ld> Q;
	vector<int> ii;
	vector<ld> as;
	rep(i,0,N){
		ll n = f_inv(s[i], P, hi);
		if (n) ii.push_back(i);
		L -= n;
		as.push_back(powl(s[i], powl(P, n)));
	}
	// cout << L << endl;
	int La;
	if (sz(ii)) {
		La = L / sz(ii);
		L = L % sz(ii);
	} else {
		La = 0;
	}

	for(auto i: ii){
		as[i] = powl(as[i], powl(P, La));
		// Q.push(as[i]);
	}
	for(auto a: as){
		Q.push(a);
	}
	// cout << L << endl;
	while(L > 0){
		ld a = Q.top();
		Q.pop();
		L--;
		a = powl(a, P);
		Q.push(a);
	}
	ld perc = 1;
	while(!Q.empty()){
		auto a = Q.top();
		Q.pop();
		perc /= a;
	}
	cout << setprecision(12) << perc << endl;

}