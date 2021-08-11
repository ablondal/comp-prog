#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5+7;

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

struct Angle {
	int x, y;
	int t;
	Angle(int x, int y, int t=0) : x(x), y(y), t(t) {}
	Angle(Point<ll> pt): x(pt.x), y(pt.y), t(0) {}
	Angle operator-(Angle b) const { return {x-b.x, y-b.y, t}; }
	int half() const {
		assert(x || y);
		return y < 0 || (y == 0 && x < 0);
	}
	Angle t90() const { return {-y, x, t + (half() && x >= 0)}; }
	Angle t180() const { return {-x, -y, t + half()}; }
	Angle t360() const { return {x, y, t + 1}; }
};
bool operator<(Angle a, Angle b) {
	// add a.dist2() and b.dist2() to also compare distances
	return make_tuple(a.t, a.half(), a.y * (ll)b.x) <
	       make_tuple(b.t, b.half(), a.x * (ll)b.y);
}

// Given two points, this calculates the smallest angle between
// them, i.e., the angle that covers the defined line segment.
pair<Angle, Angle> segmentAngles(Angle a, Angle b) {
	if (b < a) swap(a, b);
	return (b < a.t180() ?
	        make_pair(a, b) : make_pair(b, a.t360()));
}
Angle operator+(Angle a, Angle b) { // point a + vector b
	Angle r(a.x + b.x, a.y + b.y, a.t);
	if (a.t180() < r) r.t--;
	return r.t180() < a ? r.t360() : r;
}
Angle angleDiff(Angle a, Angle b) { // angle b - angle a
	int tu = b.t - a.t; a.t = b.t;
	return {a.x*b.x + a.y*b.y, a.x*b.y - a.y*b.x, tu - (b < a)};
}

pair<Point<ll>, Point<ll>> lines[MX];
int w[MX];

int gsize = 0;
vector<pair<int, int>> adj[MX];
Point<ll> pts[MX];

pair<pair<ll, ll>, pair<ll, ll>> qs[MX];

bool operator==(pair<Point<ll>, Point<ll>> a, Angle b){
	return a.first.x-a.second.x==b.x && a.first.y-a.first.y==b.y;
}

vector<pair<Angle, pair<int, int>>> adj2[MX];
vector<int> used[MX]; // 1 for in, 2 for out, 3 for both

pair<int, int> edgefaces[MX];

int facenum = 1;

int UF[4*MX] = {0};

int find(int x){
	return (UF[x]<=0)?x:UF[x] = find(x);
}
void merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a!=b) UF[a] = b;
}

void DFS(int origedg, int vert, int j, bool sd) {
	if (sd && adj2[vert][j].second.first == origedg) return;
	used[vert][j] |= 2;
	auto& angg = adj2[vert][j].first;
	angg.x *= -1;
	angg.y *= -1;
	int nxtvert = adj2[vert][j].second.second;
	auto nxtj = lower_bound(all(adj2[nxtvert]),
		make_pair(angg,make_pair(0,0)));
	int nxtjj = nxtj - adj2[nxtvert].begin();
	nxtjj = (nxtjj+1) % adj2[nxtvert].size();
	merge(adj2[vert][j].second.first, adj2[nxtvert][nxtjj].second.first);
	DFS(origedg, nxtvert, nxtjj, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	scanf("%d %d", &n, &m);
	rep(i,1,n+1){
		scanf("%d%d", &pts[i].x, &pts[i].y);
	}
	rep(i,0,m){
		int u,v,h;
		scanf("%d%d%d", &u, &v, &w[i]);
		if (! (pts[u]<pts[v]) ) swap(u,v);
		lines[i] = {pts[u], pts[v]};
		edgefaces[i] = {facenum, facenum+1};
		facenum += 2;
		adj2[u].push_back({Angle(pts[v]-pts[u]), {facenum-2, v}});
		adj2[v].push_back({Angle(pts[u]-pts[v]), {facenum-1, u}});
		used[u].push_back(0);
		used[v].push_back(0);
	}

	int q;
	scanf("%d", &q);
	rep(i,0,q){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		qs[i] = {{x1,y1},{x2,y2}};
	}

	rep(i,1,n+1){
		sort(all(adj2[i]));
	}
	rep(i,1,n+1){
		rep(j,0,adj2[i].size()){
			auto& [ang, inf] = adj2[i][j];
			auto& [edg, nx] = inf;
			if (used[i][j] & 2) continue;
			DFS(edg, i, j, 0);
		}
	}

	rep(i,1,facenum){
		if (!UF[i]){
			gsize++;
			UF[i] = -gsize;
		}
	}

	rep(i, 0, m){
		int v1 = find(edgefaces[i].first);
		int v2 = find(edgefaces[i].second);
		 v1 = -UF[v1];
		 v2 = -UF[v2];
		adj[v1].push_back({v1, w[i]});
		adj[v2].push_back({v2, w[i]});
	}

	printf("%d\n", gsize);
	rep(i,1,gsize+1){
		printf("%d:", i);
		for(auto e : adj[i]){
			printf(" %d", e);
		}
		printf("\n");
	}

	// vector<int> mm(m,0);
	// rep(i,0,m) mm[i]=i;
	// sort(all(mm), [](int a, int b){return lines[a].first<lines[b].first;});
	// rep(i,0,m){

	// }


}