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

// typedef Point<ll> P;
array<P, 2> hullDiameter(vector<P> S) {
	int n = sz(S), j = n < 2 ? 0 : 1;
	pair<ll, array<P, 2>> res({0, {S[0], S[0]}});
	rep(i,0,j)
		for(;; j=(j+1)%n) {
			res = max(res, {(S[i] - S[j]).dist2(), {S[i], S[j]}});
			if ((S[(j+1)%n] - S[j]).cross(S[i+1] - S[i]) >= 0)
				break;
		}
	return res.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<P> poly(N);
	rep(i,0,N) cin >> poly[i].x >> poly[i].y;
	
}