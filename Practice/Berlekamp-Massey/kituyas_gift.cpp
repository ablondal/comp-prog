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

// Modulo requires T to be a field, or pn to end with a 1.
template <class T>
struct polynom {
	typedef polynom pn;
	vector<T> v;
	polynom(vector<T> c): v(all(c)) {
		if (v.empty()) v.push_back(0);
		while(sz(v)>1 && v.back()==0) v.pop_back();
	}
	polynom(const pn &b): polynom(b.v) {}
	polynom(T a): polynom(vector<T>({a})) {}
	int deg() const {return sz(v)-1;}
	pn operator+(pn p) const {
		vector<T> c(max(sz(v), sz(p.v)), 0);
		rep(i,0,sz(v)) c[i] += v[i];
		rep(i,0,sz(p.v)) c[i] += p.v[i];
		return pn(c);
	}
	pn operator-(pn p) const {
		vector<T> c(max(sz(v), sz(p.v)), 0);
		rep(i,0,sz(v)) c[i] += v[i];
		rep(i,0,sz(p.v)) c[i] -= p.v[i];
		return pn(c);
	}
	pn operator*(pn p) const { // Could be improved thru FFT
		vector<T> c(sz(v)+sz(p.v)-1, 0);
		rep(i,0,sz(v)) rep(j,0,sz(p.v)) c[i+j] += v[i]*p.v[j];
		return pn(c);
	}
	pn operator*(T t) const {
		vector<T> c(all(v));
		rep(i,0,sz(v)) c[i] *= t;
		return pn(c);
	}
	pn pow_x(int a) const {
		vector<T> c(sz(v)+a, 0);
		rep(i,0,sz(v)) c[i+a] = v[i];
		return pn(c);
	}
	pn operator%(pn p) const {
		int m = p.deg();
		pn a(*this);
		vector<T> pv(m);
		rep(i,0,m) pv[i] = p.v[i] / p.v[m];
		pn b(pv);
		// cout << b << endl;
		for(int i=a.deg(); i>=m; --i){
			a = a - (b * a.v[i]).pow_x(i-m);
			a.v.pop_back();
		}
		return a;
	}
	friend ostream& operator<<(ostream& os, pn p) {
		for(int i=p.deg(); i>0; i--){
			os << p.v[i] << "x^" << i << " + ";
		}
		return os << p.v[0];
	}
};

typedef polynom<int> pn;

pn mod_pow(pn p, int x, pn m){
	pn r(p), a(1);
	// cout << a << endl;
	while(x){
		if (x & 1) {
			a = (a * r) % m;
		}
		r = (r * r) % m;
		x /= 2;
		// cout << r << endl << a << endl << x << endl;
	}
	return a;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// pn a({1, 2, 3});
	// pn b({1, 1, 1});
	// cout << a << endl;
	// cout << a*a << endl;
	// cout << (a*a) % b << endl;
	// auto c = (a*a)%b;
	// cout << c << " " << (c*2).pow_x(3) << endl;
	pn fib({1, 1, -1});
	rep(i,0,20){
		auto res = mod_pow(pn({0, 1}), i, fib);
		int fi = reduce(all(res.v), 0);
		cout << i << ": " << fi << ", " << mod_pow(pn({0, 1}), i, fib) << endl;
		// Note that our solution we actually want is the sum of terms.

	}
}