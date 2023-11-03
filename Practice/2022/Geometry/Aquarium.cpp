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

T polygonArea2(vector<P> &v){
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}

template<class P>
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

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int N;
	cin >> N;
	double D, L;
	cin >> D >> L;
	vector<P> poly(N);
	rep(i,0,N) cin >> poly[i].x >> poly[i].y;
	double lo = 1e5, hi = -1e5;
	rep(i,0,N){
		lo = min(lo, poly[i].y);
		hi = max(hi, poly[i].y);
	}
	while(hi-lo > 1e-5){
		double md = (hi+lo)/2;
		auto cut = polygonCut(poly, P(-1001, md), P(1001, md));
		auto A = polygonArea2(cut) / 2;
		if (A*D < L*1000) {
			lo = md;
		} else {
			hi = md;
		}
	}
	printf("%0.2f\n", lo);
}