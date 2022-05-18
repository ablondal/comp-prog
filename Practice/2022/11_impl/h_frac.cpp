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
const double eps = 1e-9;

struct frac{
	ll t, b;
	frac(ll a): t(a), b(1) {}
	frac(ll a, ll c): t(a), b(c) {
		ll g = gcd(t,b);
		t /= g;
		b /= g;
		if (b < 0) {t *= -1; b *= -1;}
	}
	frac operator=(int a){t=a,b=1;return *this;}
	frac operator=(ll a){t=a,b=1;return *this;}
	frac operator+(frac a) const {return frac(a.t*b+a.b*t, a.b*b);}
	frac operator-(frac a) const {return frac(a.b*t-a.t*b, a.b*b);}
	frac operator=(frac a) {t=a.t;b=a.b;return *this;}
	bool operator<(frac a) const {return t*a.b < a.t*b;}
	frac operator*(frac a) const {return frac(a.t*t, a.b*b);}
	frac operator/(frac a) const {return frac(t*a.b, a.t*b);}
	bool operator==(frac a) const {return t==a.t && b==a.b;}
	friend ostream& operator<<(ostream& os, frac f) {
		return os << f.t << "/" << f.b; }
};

int sgn(frac x) {return (x.t>0)-(x.t<0);}
struct Point{
	typedef Point P;
	typedef frac T;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const {return tie(x,y) < tie(p.x,p.y);}
	bool operator==(P p) const { return tie(x,y) == tie(p.x, p.y); }
	P operator+(P p) const {return P(x+p.x, y+p.y);}
	P operator-(P p) const {return P(x-p.x, y-p.y);}
	P operator*(T d) const {return P(d*x, d*y);}
	P operator/(T d) const {return P(x/d, y/d);}
	T dot(P p) const {return x*p.x+y*p.y;}
	T cross(P p) const {return x*p.y-y*p.x;}
	T cross(P a, P b) const {return (a-*this).cross(b-*this);}
	T dist2() const {return x*x+y*y;}
	// T dist() const{return sqrt(dist2());}
	// T angle() const {return atan2(y,x);}
	// P unit() const{return *this/dist();}
	// P perp() const{return P(-y,x);}
	// P normal() const{return perp().unit();}
	P rotate(double a) const{
		return P(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a));
	}
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
using P = Point;

// frac segDis(P& s, P& e, P& p){
// 	if (s==e) return (p-s).dist2();
// 	auto d = (e-s).dist2(), t=min(d,max(frac(0),(p-s).dot(e-s)));
// 	return ((p-s)*d-(e-s)*t).dist2()/d;
// }
bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == frac(0) && ((s - p).dot(e - p) == frac(0) || (s - p).dot(e - p) < frac(0));
}

// If parallel, returns {0, (0,0)}
// If not, returns {1, isec}
pair<int, P> lineInter(P s1, P e1, P s2, P e2){
	auto d=(e1-s1).cross(e2-s2);
	// cout << d << endl;
	if (d==frac(0))
		return {-(s1.cross(e1,s2) == frac(0) ), P(frac(0),frac(0))};
	auto p = s2.cross(e1,e2), q=s2.cross(e2,s1);
	// cout << p << " " << q << endl;
	// cout << (s1*p+e1*q) << endl;
	// cout << (s1*p+e1*q)/d << endl;
	return {1, (s1*p+e1*q)/d};
}

// If not isect, returns empty
vector<P> seginter(P a, P b, P c, P d){
	auto oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c), od = a.cross(b, d);
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a*ob-b*oa)/(ob-oa)};
	set<P> s;
	if (onSegment(c,d,a))s.insert(a);
	if (onSegment(c,d,b))s.insert(b);
	if (onSegment(a,b,c))s.insert(c);
	if (onSegment(a,b,d))s.insert(d);
	return {all(s)};
}

int n;
vector<pair<Point, Point>> lines;
pair<int, Point> isecs[13][13];
int tot = 0;

vector<Point> poly;
vector<int> segs;
int vis[13] = {0};

void dfs(int i){
	
	if (sz(segs) == n){
		// cout << "test @ " << i << endl;
		if (isecs[segs[0]][segs.back()].first == 0) return;
		auto pt = isecs[segs[0]][segs.back()].second;
		// if ( (pt-poly.back()).dist2() < eps || (pt-poly[0]).dist2() < eps ) return;
		bool w = true;
		rep(k,0,sz(poly)-2){
			if (!seginter(poly[k], poly[k+1], poly.back(), pt).empty()){
				// cout << poly[k] << " " << poly[k+1] << " " << poly.back() << " " << pt << endl;
				w = false; break;
			}
		}
		if (!w) return;
		rep(k,1,sz(poly)-1){
			if (!seginter(poly[k], poly[k+1], poly[0], pt).empty()){
				w = false; break;
			}
		}
		if (!w) return;
		tot++;
		return;
	}
	// cout << "+" << i << endl;
	rep(j,0,n){
		if (!vis[j] && isecs[i][j].first != 0){
			// if (!poly.empty() && (poly.back()-isecs[i][j].second).dist2() < eps ) continue;
			bool w = true;
			rep(k,0,sz(poly)-2){
				if (!seginter(poly[k], poly[k+1], poly.back(), isecs[i][j].second).empty()){
					w = false; break;
				}
			}
			if (w) {
				vis[j] = true;
				segs.push_back(j);
				poly.push_back(isecs[i][j].second);
				dfs(j);
				poly.pop_back();
				segs.pop_back();
				vis[j] = false;
			}
		}
	}
	// cout << "-" << i << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	lines.resize(n);
	rep(i,0,n){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		lines[i].first.x = a;
		lines[i].first.y = b;
		lines[i].second.x = c;
		lines[i].second.y = d;
		// cin >> lines[i].first.x >> lines[i].first.y >> lines[i].second.x >> lines[i].second.y;
	}
	rep(i,0,n){
		rep(j,0,n){
			if (i==j) continue;
			isecs[i][j] = lineInter(lines[i].first, lines[i].second, lines[j].first, lines[j].second);
			// cout << i << " " << j << " " << isecs[i][j].first << " " << isecs[i][j].second << endl;
		}
	}
	vis[0] = true;
	segs.push_back(0);
	dfs(0);
	cout << tot/2 << endl;
}