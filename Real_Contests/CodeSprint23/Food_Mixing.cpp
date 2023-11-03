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

int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

int sideOf(const P& s, const P& e, const P& p, double eps) {
	auto a = (e-s).cross(p-s);
	double l = (e-s).dist()*eps;
	return (a > l) - (a < -l);
}

// double segDist(P& s, P& e, P& p) {
// 	if (s==e) return (p-s).dist();
// 	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
// 	return ((p-s)*d-(e-s)*t).dist()/d;
// }

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

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

double minimize_dist(P tt, P aa, P bb){
	// Tri search to find alpha to minimize distance between
	// t and (alpha) a + (1-alpha) b
	Point<double> a, b, t;
	a.x = aa.x; a.y = aa.y;
	b.x = bb.x; b.y = bb.y;
	t.x = tt.x; t.y = tt.y;
	double hi = 1, lo = 0;
	while(hi-lo > 1e-12) {
		double md1 = lo + (1/3.0)*(hi-lo);
		double md2 = lo + (2/3.0)*(hi-lo);
		Point<double> p1 = a + (b-a)*md1;
		Point<double> p2 = a + (b-a)*md2;
		if ( (t-p1).dist2() < (t-p2).dist2() ) {
			hi = md2;
		} else {
			lo = md1;
		}
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<P> pts(n);
	rep(i,0,n){
		cin >> pts[i].x;
	}
	rep(i,0,n){
		cin >> pts[i].y;
	}
	P target;
	cin >> target.x >> target.y;
	// cout << pts[0] << " " << pts[1] << endl;
	// cout << target << endl;
	
	// if (n == 1) {
	// 	if (target == pts[0]) {
	// 		cout << "Yes" << endl;
	// 		cout << 1 << endl;
	// 	} else {
	// 		cout << "No" << endl;
	// 	}
	// } else if (n == 2) {
	// 	if (onSegment(pts[0], pts[1], target)){
	// 		cout << "Yes" << endl;
	// 		double a = minimize_dist(target, pts[0], pts[1]);
	// 		cout << setprecision(12) << a << " " << 1.0-a << endl;
	// 	} else {
	// 		cout << "No" << endl;
	// 	}
	// } else {
		// rep(i,0,n){
		// 	cout << pts[i] << endl;
		// }
		// cout << target << endl;
		auto hull = convexHull(pts);
		if (inHull(hull, target)) {
			cout << "Yes" << setprecision(12) << endl;
			if (sz(hull) == 1) {
				rep(i,0,n){
					if (pts[i] == hull[0]){
						cout << 1;
						hull[0].x = -1;
					} else {
						cout << 0;
					}
					cout << " ";
				}
				cout << endl;
				return 0;
			}
			if (sz(hull) == 2) {
				Point<double> a(hull[0].x, hull[0].y),
						b(hull[1].x, hull[1].y),
						p(target.x, target.y);
				double aa;
				if (a.x != b.x) {
					aa = (p.x - b.x) / (a.x-b.x);
				} else {
					aa = (p.y - b.y) / (a.y-b.y);
				}
				rep(i,0,n){
					if (pts[i] == hull[0]){
						cout << aa;
						hull[0].x = -1;
					} else if (pts[i] == hull[1]){
						cout << 1-aa;
						hull[1].x = -1;
					} else {
						cout << 0;
					}
					cout << " ";
				}
				cout << endl;
				return 0;
			}
			// for(auto pt: hull){
			// 	cout << pt << endl;
			// }
			vector<double> ps(n, 0);
			rep(j,2,sz(hull)){
				vector<P> newHull({hull[0], hull[1], hull[j]});
				if (inHull(newHull, target)){
					Point<double> a(hull[0].x, hull[0].y),
						b(hull[1].x, hull[1].y), c(hull[j].x, hull[j].y),
						p(target.x, target.y);
					double d = a.cross(b) + b.cross(c) + c.cross(a);
					double wa = (b.cross(c) + p.cross(b-c))/d;
					double wb = (c.cross(a) + p.cross(c-a))/d;
					double wc = (a.cross(b) + p.cross(a-b))/d;
					rep(i,0,n){
						if (pts[i] == hull[0]){
							cout << wa;
							hull[0].x = -1;
						} else if (pts[i] == hull[1]){
							cout << wb;
							hull[1].x = -1;
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
		} else {
			cout << "No" << endl;
		}
	// }




}