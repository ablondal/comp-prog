#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// typedef long double double;
const double PI = acos(-1);

// ty kactl
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

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

// double lineDist(const P& a, const P& b, const P& p) {
// 	return (double)(b-a).cross(p-a)/(b-a).dist();
// }

int DP[2007];
P pts[2007];

// int ccw(double ang1, double ang2){
// 	double b = ang2-ang1;
// 	while(b > PI) b -= 2*PI;
// 	while(b < -PI) b += 2*PI;
// 	if (b >= 0) return true;
// 	else return false;
// }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	double d;
	cin >> n >> d;
	double d2 = d*d;
	rep(i,0,n){
		DP[i] = 1e9;
		cin >> pts[i].x >> pts[i].y;
	}
	DP[0] = 1;
	rep(i,0,n-1){
		int j = i+1;
		// Have I actually found a min and a max angle?
		// Stays at no so long as pts[j] within d of pts[i]
		bool angdef = false;
		// angle trick so that the angle used by pts[j] is within
		// the right bounds to be comparable to max- and min- angle.
		int mode = 0;
		double minang;
		double maxang;

		P farthest; // = {0,0};
		minang = -1e5;
		maxang = 1e5;

		while(j < n){
			P a = pts[j]-pts[i];
			double ang1 = atan2(a.y, a.x);
			if (ang1 > 0.5*PI && mode==1) ang1 -= 2*PI;
			if (ang1 < -0.5*PI && mode==2) ang1 += 2*PI;
			
			// Get maximum angle diff that a ray could have and still
			// come within distance d of the point.
			double side2 = a.dist2() - d2;
			double angsiz;
			if (side2 < 0) angsiz = 1e5;
			else angsiz = atan2(d, sqrt(side2));

			if (a.dist2() <= d2){
				; // Will work with any pill shape, might not be a transition though
			} else if (angdef == false) {
				
				minang = ang1-angsiz;
				maxang = ang1+angsiz;
				if (minang < -0.5*PI) mode = 1;
				else if (maxang > 0.5*PI) mode = 2;
				farthest = a;
				angdef = true;
			} else {
				// update minang and maxang
				// if (ccw(minang, ang1-angsiz)){
				// 	minang = ang1-angsiz;
				// }
				// if (ccw(ang1+angsiz, maxang)){
				// 	maxang = ang1+angsiz;
				// }
				minang = max(minang, ang1-angsiz);
				maxang = min(maxang, ang1+angsiz);
				// update farthest. If a is farther away than everything else,
				// its ray will hit everything else so long as it's within
				// the right angle range.
				if (a.dist2() >= farthest.dist2()){
					farthest = a;
				}
			}
			P ad;
			if (minang <= ang1 && ang1 <= maxang && segDist(ad, a, farthest) <= d){
				DP[j] = min(DP[j], DP[i]+1);
			}
			if (minang > maxang) break;

			j++;
		}
	}
	// rep(i,0,n-1) cout << DP[i] << " ";

	cout << DP[n-1] << endl;
}