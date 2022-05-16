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
using T = double;

int sgn(T x) { return (x > 0) - (x < 0); }
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
using P = Point;

pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

P ccCenter(const P& A, const P& B, const P& C) {
	P b = C-A, c = B-A;
	return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

P pts[41];
int n;
int m;

inline void gnum(P C){
	vector<double> dds;
	rep(i,0,n){
		dds.push_back( (C - pts[i]).dist2() );
	}
	sort(all(dds));
	int tot = n;
	rep(i,1,n){
		if (dds[i]-dds[i-1] < 1e-9) tot--;
	}
	m = min(m, tot);
}

inline void ctdiff(P a, P b, P c, P d){
	P s1 = (a+b)/2;
	P s2 = (c+d)/2;
	P e1 = s1 + (b-a).perp();
	P e2 = s2 + (d-c).perp();
	auto res = lineInter(s1, e1, s2, e2);
	if (res.first == 0) return;
	if (res.first == -1) return;
	gnum(res.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int n;
	cin >> n;
	rep(i,0,n){
		cin >> pts[i].x >> pts[i].y;
	}
	m = max(1, n-2);
	rep(i,0,n){
		rep(j,i+1,n){
			rep(k,j+1,n){
				rep(l,k+1,n){
					ctdiff(pts[i], pts[j], pts[k], pts[l]);
					ctdiff(pts[i], pts[k], pts[j], pts[l]);
					ctdiff(pts[i], pts[l], pts[j], pts[k]);
				}
			}
		}
	}
	rep(i,0,n){
		rep(j,i+1,n){
			rep(k,j+1,n){
				auto C = ccCenter(pts[i], pts[j], pts[k]);
				gnum(C);
			}
		}
	}
	rep(i,0,n){
		rep(j,i+1,n){
			auto C = (pts[i]+pts[j])/2;
			gnum(C);
		}
	}
	cout << m << endl;
}