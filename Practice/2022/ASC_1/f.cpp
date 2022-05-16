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

using T = double;
int sgn(T d) {return (d>0)-(d<0);}
struct Point{
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const{return tie(x,y) < tie(p.x,p.y);}
	bool operator==(P p) const{return tie(x,y)==tie(p.x,p.y);}
	P operator+(P p) const{return P(x+p.x,y+p.y);}
	P operator-(P p) const{return P(x-p.x,y-p.y);}
	P operator*(T d) const{return P(x*d,y*d);}
	P operator/(T d) const{return P(x/d,y/d);}
	T dot(P p) const{return x*p.x + y*p.y;}
	long double cross(P p) const{return x*p.y - y*p.x;}
	long double cross(P a, P b) const{return (a-*this).cross(b-*this);}
	long double dist2() const {return (long double)x*x+(long double)y*y;}
	double dist() const{return sqrt((double)dist2());}
	double angle() const {return atan2(y,x);}
	P unit() const {return *this/dist();}
	P perp() const {return P(-y, x);}
	P normal() const{return perp().unit();}
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
	}
	friend ostream& operator<<(ostream& os, P p){
		return os << "(" << p.x << "," << p.y << ")";
	}
};
using P = Point;

typedef struct Quad* Q;
typedef long double lll;
P arb(LLONG_MAX, LLONG_MAX);

struct Quad {
	Q rot, o; P p = arb; bool mark;
	P& F() {return r()->p;}
	Q& r() {return rot->rot;}
	Q prev() {return rot->o->rot;}
	Q next() {return r()->prev();}
} *H;

bool circ(P p, P a, P b, P c){
	lll p2 = p.dist2(), A = a.dist2() - p2,
		B = b.dist2()-p2, C = c.dist2()-p2;
	return p.cross(a,b)*C + p.cross(b,c)*A + p.cross(c,a)*B > 0;
}
Q makeEdge(P orig, P dest) {
	Q r = H ? H : new Quad{new Quad{new Quad{new Quad{0}}}};
	H = r->o; r->r()->r() = r;
	rep(i,0,4) r = r->rot, r->p = arb, r->o = i & 1 ? r : r->r();
	r->p = orig; r->F() = dest;
	return r;
}
void splice(Q a, Q b){
	swap(a->o->rot->o, b->o->rot->o); swap(a->o, b->o);
}
Q connect(Q a, Q b){
	Q q = makeEdge(a->F(), b->p);
	splice(q, a->next());
	splice(q->r(), b);
	return q;
}

pair<Q,Q> rec(const vector<P>& s){
	if (sz(s) <= 3){
		Q a = makeEdge(s[0], s[1]), b = makeEdge(s[1], s.back());
		if (sz(s)==2) return {a, a->r()};
		splice(a->r(), b);
		auto side = s[0].cross(s[1], s[2]);
		Q c = side ? connect(b, a) : 0;
		return {side < 0 ? c->r() : a, side < 0 ? c : b->r()};
	}

#define H(e) e->F(), e->p
#define valid(e) (e->F().cross(H(base)) > 0)
	
	Q A, B, ra, rb;
	int half = sz(s)/2;
	tie(ra, A) = rec({all(s)-half});
	tie(B, rb) = rec({sz(s) - half + all(s)});
	while((B->p.cross(H(A)) < 0 && (A = A->next())) ||
		(A->p.cross(H(B)) > 0 && (B = B->r()->o)));
	Q base = connect(B->r(), A);
	if (A->p == ra->p) ra = base->r();
	if (B->p == rb->p) rb = base;

#define DEL(e, init, dir) Q e = init->dir; if (valid(e)) \
while(circ(e->dir->F(), H(base), e->F())) { \
	Q t = e->dir; \
	splice(e, e->prev()); \
	splice(e->r(), e->r()->prev()); \
	e->o = H; H = e; e=t; \
}

	for(;;){
		DEL(LC, base->r(), o); DEL(RC, base, prev());
		if (!valid(LC) && !valid(RC)) break;
		if (!valid(LC) || (valid(RC) && circ(H(RC), H(LC))))
			base = connect(RC, base->r());
		else
			base = connect(base->r(), LC->r());
	}	
	return {ra, rb};
}

vector<P> triangulate(vector<P> pts){
	sort(all(pts)); assert(unique(all(pts)) == pts.end());
	if (sz(pts) < 2) return {};
	Q e = rec(pts).first;
	vector<Q> q = {e};
	int qi = 0;
	while(e->o->F().cross(e->F(), e->p) < 0) e = e->o;
# define ADD {Q c = e; do{c->mark = 1; pts.push_back(c->p); \
q.push_back(c->r()); c=c->next();} while (c != e); }
	ADD; pts.clear();
	while(qi < sz(q)) if (!(e = q[qi++])->mark) ADD;
	return pts;
}

vi adj[1000];
char vis[1000] = {0};
map<P, double> rr;
double R;
map<pair<P, P>, int> edg;

bool passable(P a, P b){
	// cout << a << " " << b << endl;
	// cout << rr[a] + rr[b] + 2*R << " " << (a-b).dist() << endl;
	if (rr[a] + rr[b] + 2*R < (a-b).dist() + eps) return 1;
	return 0;
}

void dfs(int v){
	if (vis[v]) return;
	vis[v] = true;
	for(auto & e : adj[v]){
		dfs(e);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream in("out.in");
	ofstream out("out.out");

	int n;
	in >> n;

	vector<pair<P, double>> circs;
	rep(i,0,n){
		double x, y, r;
		in >> x >> y >> r;
		bool g = true;
		rep(j,0,sz(circs)){
			if ( (circs[j].first - P(x,y)).dist() < eps) {
				circs[j].second = max(circs[j].second, r);
				g = false; break;
			}
		}
		if (g) {
			circs.push_back({P(x,y), r});
		}
	}
	double x, y;
	in >> x >> y >> R;
	vector<P> pts;
	rep(i,0,sz(circs)){
		pts.push_back(circs[i].first);
		rr[circs[i].first] = circs[i].second;
	}
	auto tris = triangulate(pts);
	vector<P> origtri(all(tris));
	for(int i=0; i<sz(tris); i+=3){
		sort(tris.begin()+i, tris.begin()+i+3);
		// cout << tris[i] << " " << tris[i+1] << " " << tris[i+2] << endl;

		pair<P, P> e1(tris[i], tris[i+1]), e2(tris[i], tris[i+2]), e3(tris[i+1], tris[i+2]);
		if (!edg.count(e1)) edg[e1] = i/3;
		else {
			if ( passable(tris[i], tris[i+1]) ) {adj[i/3].push_back(edg[e1]); adj[edg[e1]].push_back(i/3);}
			edg.erase(e1);
		}
		if (!edg.count(e2)) edg[e2] = i/3;
		else {
			if ( passable(tris[i], tris[i+2]) ) {adj[i/3].push_back(edg[e2]); adj[edg[e2]].push_back(i/3);}
			edg.erase(e2);
		}
		if (!edg.count(e3)) edg[e3] = i/3;
		else {
			if ( passable(tris[i+1], tris[i+2]) ) {adj[i/3].push_back(edg[e3]); adj[edg[e3]].push_back(i/3);}
			edg.erase(e3);
		}
	}

	int outside = (sz(tris)/3) + 1;
	for(auto e : edg){
		if (passable(e.first.first, e.first.second)){
			adj[e.second].push_back(outside);
		}
	}

	int start = -1;
	P o(x, y);
	for(int i=0; i<sz(origtri); i+=3){
		int a1 = sgn(o.cross(origtri[i], origtri[i+1]));
		int a2 = sgn(o.cross(origtri[i+1], origtri[i+2]));
		int a3 = sgn(o.cross(origtri[i+2], origtri[i]));
		if (a1 == 0 || a2 == 0 || a3 == 0 || ( a1 == a2 && a2 == a3) ) {
			start = i/3;
			break;
		}
	}

	// cout << start << endl;
	// rep(i,0,outside){
	// 	cout << i << ":";
	// 	for(auto& e : adj[i]) cout << " " << e;
	// 	cout << endl;
	// }

	if (start == -1){
		out << "YES" << endl;
		return 0;
	}

	dfs(start);
	if (vis[outside]){
		out << "YES" << endl;
	} else {
		out << "NO" << endl;
	}


}