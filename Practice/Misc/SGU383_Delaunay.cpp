#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// done with an ungodly amount of book code
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
typedef struct Quad* Q;
typedef __int128_t lll; // (can be ll if coords are < 2e4)
P arb(LLONG_MAX,LLONG_MAX); // not equal to any other point

struct custom_hash {
	// From https://codeforces.com/blog/entry/62393
    const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(P x) const {
    	return splitmix64( x.x ^ (x.y>>1) + FIXED_RANDOM );
    }
};

struct Quad {
	Q rot, o; P p = arb; bool mark;
	P& F() { return r()->p; }
	Q& r() { return rot->rot; }
	Q prev() { return rot->o->rot; }
	Q next() { return r()->prev(); }
} *H;

bool circ(P p, P a, P b, P c) { // is p in the circumcircle?
	lll p2 = p.dist2(), A = a.dist2()-p2,
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
void splice(Q a, Q b) {
	swap(a->o->rot->o, b->o->rot->o); swap(a->o, b->o);
}
Q connect(Q a, Q b) {
	Q q = makeEdge(a->F(), b->p);
	splice(q, a->next());
	splice(q->r(), b);
	return q;
}

pair<Q,Q> rec(const vector<P>& s) {
	if (sz(s) <= 3) {
		Q a = makeEdge(s[0], s[1]), b = makeEdge(s[1], s.back());
		if (sz(s) == 2) return { a, a->r() };
		splice(a->r(), b);
		auto side = s[0].cross(s[1], s[2]);
		Q c = side ? connect(b, a) : 0;
		return {side < 0 ? c->r() : a, side < 0 ? c : b->r() };
	}

#define H(e) e->F(), e->p
#define valid(e) (e->F().cross(H(base)) > 0)
	Q A, B, ra, rb;
	int half = sz(s) / 2;
	tie(ra, A) = rec({all(s) - half});
	tie(B, rb) = rec({sz(s) - half + all(s)});
	while ((B->p.cross(H(A)) < 0 && (A = A->next())) ||
	       (A->p.cross(H(B)) > 0 && (B = B->r()->o)));
	Q base = connect(B->r(), A);
	if (A->p == ra->p) ra = base->r();
	if (B->p == rb->p) rb = base;

#define DEL(e, init, dir) Q e = init->dir; if (valid(e)) \
		while (circ(e->dir->F(), H(base), e->F())) { \
			Q t = e->dir; \
			splice(e, e->prev()); \
			splice(e->r(), e->r()->prev()); \
			e->o = H; H = e; e = t; \
		}
	for (;;) {
		DEL(LC, base->r(), o);  DEL(RC, base, prev());
		if (!valid(LC) && !valid(RC)) break;
		if (!valid(LC) || (valid(RC) && circ(H(RC), H(LC))))
			base = connect(RC, base->r());
		else
			base = connect(base->r(), LC->r());
	}
	return { ra, rb };
}

vector<P> triangulate(vector<P> pts) {
	sort(all(pts));  assert(unique(all(pts)) == pts.end());
	if (sz(pts) < 2) return {};
	Q e = rec(pts).first;
	vector<Q> q = {e};
	int qi = 0;
	while (e->o->F().cross(e->F(), e->p) < 0) e = e->o;
#define ADD { Q c = e; do { c->mark = 1; pts.push_back(c->p); \
	q.push_back(c->r()); c = c->next(); } while (c != e); }
	ADD; pts.clear();
	while (qi < sz(q)) if (!(e = q[qi++])->mark) ADD;
	return pts;
}

int UF[100007];
ll UW[100007];
int dep[100007];

int find(int x){
	return (UF[x]<0) ? x : find(UF[x]);
}

inline void merge(int a, int b, ll w){
	// printf("merging %d, %d with %lld\n", a, b, w);
	a = find(a);
	b = find(b);
	if (a==b) return;
	if (a<b){
		UF[a] += UF[b];
		UF[b] = a;
		UW[b] = w;
	} else {
		UF[b] += UF[a];
		UF[a] = b;
		UW[a] = w;
	}	
}

int getdep(int v){
	if (dep[v]) return dep[v];
	if (UF[v]<0) return 1;
	return dep[v] = getdep(UF[v])+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	scanf("%d", &n);
	vector<P> pts(n);
	gp_hash_table<P, int, custom_hash> ind;
	rep(i,0,n){
		scanf("%lld%lld", &pts[i].x, &pts[i].y);
		ind[pts[i]] = i+1;
	}
	auto delaun = triangulate(pts);
	
	vector<pair<ll, pair<int, int>>> edgs;

	for(int i=0; i<delaun.size()/3; ++i){
		auto pt1 = delaun[3*i];
		auto pt2 = delaun[3*i+1];
		auto pt3 = delaun[3*i+2];
		// cout << pt1 << " " << pt2 << " " << pt3 << endl;
		auto v1 = ind[pt1];
		auto v2 = ind[pt2];
		auto v3 = ind[pt3];
		// cout << v1 << " " << v2 << " " << v3 << endl;
		edgs.push_back({(pt1-pt2).dist2(), {v1, v2}});
		edgs.push_back({(pt3-pt2).dist2(), {v3, v2}});
		edgs.push_back({(pt1-pt3).dist2(), {v1, v3}});
	}
	sort(all(edgs));

	rep(i,0,100007) UW[i] = 0, UF[i] = -1;

	rep(i,0,sz(edgs)){
		merge(edgs[i].second.first, edgs[i].second.second, edgs[i].first);
	}

	rep(i,1,n+1){
		auto _ = getdep(i);
		// cout << UF[i] << " " << UW[i] << endl;
	}

	int q;
	scanf("%d", &q);
	while(q--){
		int a, b;
		scanf("%d%d", &a, &b);
		ll M = 0;
		int v1 = a;
		int v2 = b;
		// printf("%d %d\n", v1, v2);
		while(dep[v1] > dep[v2]){
			M = max(M, UW[v1]);
			v1 = UF[v1];
		}
		while(dep[v2] > dep[v1]){
			M = max(M, UW[v2]);
			v2 = UF[v2];
		}
				// printf("%d %d\n", v1, v2);

		while(v1 != v2){
			M = max(M, UW[v1]);
			v1 = UF[v1];
			M = max(M, UW[v2]);
			v2 = UF[v2];
		}
		// printf("%d %d\n", v1, v2);

		printf("%.10f\n", sqrt(M));
	}

}