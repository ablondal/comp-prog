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
typedef Point P;

int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<P> pts(n);
	rep(i,0,n){
		cin >> pts[i].x >> pts[i].y;
	}
	int M = 0;
	rep(i,0,n){
		rep(j,i+1,n){
			vector<P> a;
			vector<P> b;
			rep(k,0,n){
				if (k != i && k != j){
					if (sideOf(pts[i], pts[j], pts[k]) == 1) {
						a.push_back(pts[k]);
					} else {
						b.push_back(pts[k]);
					}
				}
			}
			// cout << sz(a) << " " << sz(b) << endl;
			if (sz(a) < 2 || sz(b) < 2) continue;
			if (sz(a) != sz(b)) continue;
			a.push_back(pts[i]); b.push_back(pts[j]);
			M = max(M, sz(convexHull(a))+sz(convexHull(b)));
			// if (sz(convexHull(a))+sz(convexHull(b)) == 9) {
			// 	cout << "a:";
			// 	for(auto pp: a) cout << " " << pp;
			// 	cout << endl;
			// 	cout << "b:";
			// 	for(auto pp: b) cout << " " << pp;
			// 	cout << endl;
			// }
			a.pop_back(); b.pop_back();
			a.push_back(pts[j]); b.push_back(pts[i]);
			M = max(M, sz(convexHull(a))+sz(convexHull(b)));
			// if (sz(convexHull(a))+sz(convexHull(b)) == 9) {
			// 	cout << "a:";
			// 	for(auto pp: a) cout << " " << pp;
			// 	cout << endl;
			// 	cout << "b:";
			// 	for(auto pp: b) cout << " " << pp;
			// 	cout << endl;
			// }
			a.pop_back(); b.pop_back();
			

		}
	}
	cout << n-M << endl;
}