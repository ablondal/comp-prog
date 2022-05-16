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

struct frac{
	ll t, b;
	frac(ll tt, ll bb): t(tt), b(bb) {
		ll g = gcd(t, b);
		t /= g;
		b /= g;
		if (b < 0) {
			t *= -1;
			b *= -1;
		}
	}
	frac(ll a): t(a), b(1) {}
	frac operator+(frac c) const { return frac(t*c.b + c.t*b, c.b*b); }
	frac operator-(frac c) const { return frac(t*c.b - c.t*b, c.b*b); }
	frac operator*(frac c) const { return frac(t*c.t, b*c.b); }
	frac operator/(frac c) const { return frac(t*c.b, b*c.t); }
	bool operator==(frac c) const { return tie(t,b) == tie(c.t, c.b); }
	bool operator==(ll c) const { return *this == frac(c); }
	friend ostream& operator<<(ostream& os, frac f){
		return os << f.t << '/' << f.b;
	}
	bool operator<(frac c) const { return t*c.b < c.t*b; }
};

using T = frac;
// template<class T>
struct Point {
	typedef Point P;
	frac x, y;
	explicit Point(frac x=0, frac y=0) : x(x), y(y) {}
	bool operator==(P p) const { return tie(x,y)==tie(p.x, p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	bool operator<(P p) const { return tie(x,y) < tie(p.x, p.y); }
	friend ostream& operator<<(ostream& os, P p){
		return os << "(" << p.x << "," << p.y << ")";
	}
};

using P = Point;

pair<int, P> lineInter(P s1, P e1, P s2, P e2){
	auto d = (e1 - s1).cross(e2 - s2);
	if (d==0) return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1*q)/d};
}

vector<P> polygonCut(const vector<P>& poly, P s, P e){
	vector<P> res;
	rep(i,0,sz(poly)){
		P cur = poly[i], prev = i ? poly[i-1] : poly.back();
		bool side = s.cross(e, cur) < frac(0);
		if (side != (s.cross(e, prev) < frac(0) ))
			res.push_back(lineInter(s, e, cur, prev).second);
		if (side)
			res.push_back(cur);
	}
	return res;
}

T polygonArea2( vector<P>& v) {
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a = a + v[i].cross(v[i+1]);
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	vector<P> poly;
	rep(i,0,N){
		int r, c;
		cin >> r >> c;
		// r = 1000 - r;
		poly.push_back(P(frac(c), frac(r)));
	}
	reverse(all(poly));
	// rep(i,0,sz(poly)){
	// 	cout << poly[i] << " ";
	// }
	// cout << endl;

	rep(i,0,Q){
		int x, y;
		cin >> y >> x;
		// r = 1000 - r;
		// int x = c, y = r;

		frac xmin(2*x-1, 2), xmax(2*x+1, 2);
		frac ymin(2*y-1, 2), ymax(2*y+1, 2);

		vector<P> newpoly = {P(xmin, ymin), P(xmax, ymin), P(xmax, ymax), P(xmin, ymax)};
		// rep(i,0,sz(newpoly)){
		// 	cout << newpoly[i] << " ";
		// }
		// cout << endl;

		rep(j,0,sz(poly)){
			newpoly = polygonCut(newpoly, poly[(j+1)%sz(poly)], poly[j]);

			// rep(i,0,sz(newpoly)){
			// 	cout << newpoly[i] << " ";
			// }
			// cout << endl;

			if (newpoly.empty()) break;
		}
		if (newpoly.empty()) cout << frac(0) << endl;
		else {
			frac area = polygonArea2(newpoly) / frac(2);
			cout << area << endl;
		}
	}
}