#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef ll T;
int sgn(T x) {return (x>0) - (x<0);}
struct Point{
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const {return tie(x,y) < tie(p.x, p.y);}
	bool operator==(P p) const {return tie(x,y) == tie(p.x, p.y);}
	P operator+(P p) const {return P(x+p.x, y+p.y);}
	P operator-(P p) const {return P(x-p.x, y-p.y);}
	P operator*(T d) const {return P(x*d, y*d);}
	P operator/(T d) const {return P(x/d, y/d);}
	T dot(P p) const {return x*p.x + y*p.y;}
	T cross(P p) const {return x*p.y - y*p.x;}
	T cross(P a, P b) const {return (a-*this).cross(b-*this);}
	T dist2() const {return x*x + y*y;}
	double dist() const {return sqrt((double)dist2());}
	double angle() const {return atan2(y, x);}
	P unit() const {return *this/dist();}
	P perp() const {return P(-y, x);}
	P normal() const {return perp().unit();}
	P rotate(double a) const {
		return P(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p){
		return os << "(" << p.x << "," << p.y << ")"; }
};
typedef Point P;

vector<P> convexHull(vector<P> pts){
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h(sz(pts)+1);
	int s=0, t=0;
	for(int it=2; it--; s=--t, reverse(all(pts)))
		for(P p: pts) {
			while(t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t==2 && h[0] == h[1])};
}

array<P, 2> hullDiameter(vector<P> S) {
	int n = sz(S), j= n<2 ? 0 : 1;
	pair<ll, array<P, 2>> res({0, {S[0], S[0]}});
	rep(i,0,j)
		for(;; j=(j+1)%n) {
			res = max(res, {(S[i]-S[j]).dist2(), {S[i], S[j]}});
			if ((S[(j+1)%n] - S[j]).cross(S[i+1] - S[i]) >= 0)
				break;
		}
	return res.second;
}

int main(){
	cin.tie(0) ->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vector<P> pts(n);
	rep(i,0,n) cin >> pts[i].x >> pts[i].y;
	auto h = convexHull(pts);
	auto [p1, p2] = hullDiameter(h);
	double d = (p1-p2).dist();
	cout << setprecision(12) << d << endl;
}