#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const long double eps = 1e-9;
using ld = long double;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return (*this-p).dist() < eps; }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	ld dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	ld angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

// {1, pt} is inter
// {0, } means none
// {-1, } means inf
template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (abs(d) < 1e-9) // if parallel
		return {-( abs(s1.cross(e1, s2)) < eps), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

typedef Point<ld> P;
double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0L,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

Point<ld> pts[1007];
pair<Point<ld>, Point<ld>> lines[107];

bool sameSideOfLine(int line, Point<ld> pt1, Point<ld> pt2) {
	return pt1.cross(lines[line].first, lines[line].second) * pt2.cross(lines[line].first, lines[line].second) > 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	rep(i,0,n){
		cin >> pts[i].x >> pts[i].y;
	}
	rep(i,0,m){
		cin >> lines[i].first.x >> lines[i].first.y >> lines[i].second.x >> lines[i].second.y;
	}
	vector<Point<ld>> isecs;
	rep(i,0,m){
		rep(j,0,n){

		}
		if ( abs(lines[i].first.x-lines[i].second.x) / abs(lines[i].first.y - lines[i].second.y) <= 0.3 ){
			for(auto& is : isecs){
				is = is.perp();
			}
		}

		double dist = 0;
		sort(all(isecs));
		rep(j,0,sz(isecs)/2){
			// cout << isecs[2*j] << " " << isecs[2*j+1] << endl;
			dist += (isecs[2*j]-isecs[2*j+1]).dist();
		}
		cout << setprecision(18) << dist << endl;
		isecs.clear();
	}
}