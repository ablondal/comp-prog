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

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
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

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h(sz(pts)+1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(all(pts)))
		for (P p : pts) {
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

int sideOf(const P& s, const P& e, const P& p, double eps) {
	auto a = (e-s).cross(p-s);
	double l = (e-s).dist()*eps;
	return (a > l) - (a < -l);
}

bool inHull(const vector<P>& l, P p, bool strict = false) {
	int a = 1, b = sz(l) - 1, r = !strict;
	if (sz(l) < 3) return r && onSegment(l[0], l.back(), p);
	if (sideOf(l[0], l[a], l[b]) > 0) swap(a, b);
	if (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p)<= -r)
		return false;
	while (abs(a - b) > 1) {
		int c = (a + b) / 2;
		(sideOf(l[0], l[c], p) > 0 ? b : a) = c;
	}
	return sgn(l[a].cross(l[b], p)) < r;
}

tuple<double, double, double> inTri(P a, P b, P c, P p){
	double d = a.cross(b) + b.cross(c) + c.cross(a);
	ll wa = b.cross(c) + p.cross(b-c);
	ll wb = c.cross(a) + p.cross(c-a);
	ll wc = a.cross(b) + p.cross(a-b);
	return {wa / d, wb / d, wc / d};
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// auto [a,b,c] = inTri(P(1, 2), P(0, 0), P(0, 1), P(0,1));
	// cout << a << " " << b << " " << c << endl;
	int n;
	cin >> n;
	vector<P> pts(n);
	rep(i,0,n) cin >> pts[i].x;
	rep(i,0,n) cin >> pts[i].y;
	P targ;
	cin >> targ.x >> targ.y;
	auto hull = convexHull(pts);
	if (inHull(hull, targ)) {
		cout << "Yes" << setprecision(18) << endl;
		if (sz(hull) == 1) {
			// cout << "ALSKDJALSKDJ" << endl;
			rep(i,0,n){
				if (pts[i] == hull[0]){
					hull[0].x = -1;
					cout << 1 << " ";
				} else {
					cout << 0 << " ";
				}
			}
			cout << endl;
		} else if (sz(hull) == 2) {
			cd a(hull[0].x, hull[0].y), b(hull[1].x, hull[1].y), p(targ.x, targ.y);
			double res = ((p-b) / (a-b)).real();
			rep(i,0,n){
				if (pts[i] == hull[0]){
					hull[0].x = -1;
					cout << res << " ";
				} else if (pts[i] == hull[1]){
					hull[1].x = -1;
					cout << 1.0-res << " ";
				} else {
					cout << 0 << " ";
				}
			}
			cout << endl;
		} else {
			rep(j,2,sz(hull)){
				vector<P> newHull({hull[0], hull[j-1], hull[j]});
				if (inHull(newHull, targ)){
					Point<double> a(hull[0].x, hull[0].y),
						b(hull[j-1].x, hull[j-1].y), c(hull[j].x, hull[j].y),
						p(targ.x, targ.y);
					double d = a.cross(b) + b.cross(c) + c.cross(a);
					double wa = (b.cross(c) + p.cross(b-c))/d;
					double wb = (c.cross(a) + p.cross(c-a))/d;
					double wc = (a.cross(b) + p.cross(a-b))/d;
					rep(i,0,n){
						if (pts[i] == hull[0]){
							cout << wa;
							hull[0].x = -1;
						} else if (pts[i] == hull[j-1]){
							cout << wb;
							hull[j-1].x = -1;
						} else if (pts[i] == hull[j]){
							cout << wc;
							hull[j].x = -1;
						} else {
							cout << 0;
						}
						cout << " ";
					}
					cout << endl;
					// cout << a*wa + b*wb + c*wc << endl;
					break;
				}
			}
		}
	} else {
		cout << "No" << endl;
	}
}