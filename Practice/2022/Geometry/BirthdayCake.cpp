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
typedef double T;

int sgn(T x) {return (x>0) - (x<0);}
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const {return tie(x,y) < tie(p.x, p.y);}
	bool operator==(P p) const {return tie(x,y) == tie(p.x,p.y);}
	P operator+(P p) const {return P(x+p.x, y+p.y);}
	P operator-(P p) const {return P(x-p.x, y-p.y);}
	P operator*(T d) const {return P(x*d, y*d);}
	P operator/(T d) const {return P(x/d, y/d);}
	T dot(P p) const {return x*p.x + y*p.y;}
	T cross(P p) const {return x*p.y - y*p.x;}
	T cross(P a, P b) const {return (a-*this).cross(b-*this);}
	T dist2() const {return x*x+y*y;}
	double dist() const {return sqrt((double)dist2());}
	double angle() const {return atan2(y,x);}
	P unit() const {return *this/dist();}
	P perp() const {return P(-y,x);}
	P normal() const {return perp().unit();}
	P rotate(double a) const {
		return P(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a));
	}
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")";
	}
};
typedef Point P;

pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1-s1).cross(e2-s2);
	if (d==0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

vector<P> polygonCut(const vector<P> &poly, P s, P e){
	vector<P> res;
	rep(i,0,sz(poly)){
		P cur = poly[i], prev = i ? poly[i-1] : poly.back();
		bool side = s.cross(e, cur) < 0;
		if (side != (s.cross(e, prev) < 0))
			res.push_back(lineInter(s, e, cur, prev).second);
		if (side)
			res.push_back(cur);
	}
	return res;
}

bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s-p).dot(e-p) <= 0;
}

double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t=min(d,max(.0, (p-s).dot(e-s)));
	return ((p-s)*d - (e-s)*t).dist()/d;
}

int sideOf(P s, P e, P p) {return sgn(s.cross(e, p));}

int sideOf(const P& s, const P& e, const P& p, double eps) {
	auto a = (e-s).cross(p-s);
	double l = (e-s).dist()*eps;
	return (a>l) - (a<-l);
}

bool inHull(const vector<P> &l, P p, bool strict=false) {
	int a=1, b=sz(l)-1, r = !strict;
	if (sz(l) < 3) return r && onSegment(l[0], l.back(), p);
	if (sideOf(l[0], l[a], l[b]) > 0) swap(a, b);
	if (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p) <= -r)
		return false;
	while(abs(a-b)>1){
		int c = (a+b)/2;
		(sideOf(l[0], l[c], p) > 0 ? b : a) = c;
	}
	return sgn(l[a].cross(l[b], p)) < r;
}

double minD(vector<P> &pol, P a){
	if (inHull(pol, a)) {
		return 0;
	}
	double m = 1e9;
	rep(i,0,sz(pol)){
		m = min(m, segDis(pol[i], pol[(i+1)%sz(pol)], a));
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, r;
	cin >> n >> m >> r;
	vector<P> candles(n);
	vector<vector<P>> polys = {{P(r, r), P(-r, r), P(-r, -r), P(r, -r)}};
	vector<vector<P>> polys2;
	rep(i,0,n) cin >> candles[i].x >> candles[i].y;
	rep(i,0,m){
		// ax + by + c = 0
		double a, b, c;
		cin >> a >> b >> c;
		P p1, p2;
		if (a != 0 && b != 0 && c != 0){
			p1 = P(0, -c/b); p2 = P(-c/a, 0);
		} else if (a == 0) {
			p1 = P(0, -c/b); p2 = P(1, -c/b);
		} else if (b == 0) {
			p2 = P(-c/a, 0); p1 = P(-c/a, 1);
		} else if (c == 0) {
			p1 = P(0, 0); p2 = P(1, -a/b);
		}
		polys2.clear();
		for(auto pol : polys){
			auto z1 = polygonCut(pol, p1, p2);
			auto z2 = polygonCut(pol, p2, p1);
			if (!z1.empty()) polys2.push_back(z1);
			if (!z2.empty()) polys2.push_back(z2);
		}
		swap(polys, polys2);
	}
	for(auto pol : polys){
		if (minD(pol, P(0, 0)) >= r-) {
			continue;
		}

		int ct = 0;
		for(auto c : candles){
			if (inHull(pol, c)) ct++;
		}
		if (ct != 1){
			cout << "no" << endl;
			exit(0);
		}
	}
	cout << "yes" << endl;

}