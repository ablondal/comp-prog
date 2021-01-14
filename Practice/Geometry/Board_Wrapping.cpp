#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <tuple>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const long double PI = acos(-1);

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

typedef Point<ld> P;
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

ld polygonArea2(vector<P> &v){
	ld a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a+= v[i].cross(v[i+1]);
	return a;
}

ld x,y,w,h,th;

int main(){
	int N;
	scanf("%d", &N);
	while(N--){
		int n;
		ld boxarea = 0;
		scanf("%d", &n);
		vector <P> pts(4*n);
		rep(i,0,n){
			scanf("%Lf%Lf%Lf%Lf%Lf", &x,&y,&w,&h,&th);
			th *= PI / 180.0;
			h /=2;
			w /=2;
			P u(sin(th)*h, cos(th)*h);
			P r(cos(th)*w, -sin(th)*w);
			P xy(x,y);
			pts[4*i] = xy + u + r;
			pts[4*i+1] = xy + u - r;
			pts[4*i+2] = xy - u + r;
			pts[4*i+3] = xy - u - r;
			boxarea += 4 * w * h;
		}
		vector<P> cvh = convexHull(pts);

		// for(auto pt : cvh){
		// 	cout << pt << " ";
		// }
		// cout << endl;

		ld polarea = polygonArea2(cvh) / 2.0;

		ld perc = 100.0 * boxarea / polarea;

		printf("%0.1Lf %%\n", perc);
	}
}




























