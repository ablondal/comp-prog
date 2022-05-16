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

const long double eps = 1e-10;

int sgn(long double x) {return (x>0)-(x<0);}
struct Point{
    typedef Point P;
    typedef long double T;
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
    T dist() const{return sqrtl(dist2());}
    T angle() const {return atan2(y,x);}
    P unit() const{return *this/dist();}
    P perp() const{return P(-y,x);}
    P normal() const{return perp().unit();}
    P rotate(double a) const{
        return P(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a));}
};
using P = Point;

double segDis(P& s, P& e, P& p){
    if (s==e) return (p-s).dist();
    auto d = (e-s).dist2(), t=min(d,max(.0L,(p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}

// If parallel, returns {0, (0,0)}
// If not, returns {1, isec}
pair<int, P> lineInter(P s1, P e1, P s2, P e2){
    auto d=(e1-s1).cross(e2-s2);
    if (d==0)
        return {-(s1.cross(e1,s2)==0), P(0,0)};
    auto p = s2.cross(e1,e2), q=s2.cross(e2,s1);
    return {1, (s1*p+e1*q)/d};
}

// If not isect, returns empty
vector<P> seginter(P a, P b, P c, P d){
    auto oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return {(a*ob-b*oa)/(ob-oa)};
    set<P> s;
    if (segDis(c,d,a)<eps)s.insert(a);
    if (segDis(c,d,b)<eps)s.insert(b);
    if (segDis(a,b,c)<eps)s.insert(c);
    if (segDis(a,b,d)<eps)s.insert(d);
    return {all(s)};
}

int n;
vector<pair<Point, Point>> lines;
int isec_id[13][13];
int Mi = 0;
vector<Point> is_pts;
pair<int, Point> isecs[13][13];
int tot = 0;

char vis[13] = {0};
vi segs;
vector<pair<int, int>> poly;
int tot = 0;

bool onseg(int a, int b, int c, int d, int e, int f){
    if (isec_id[a][b] == isec_id[c][d] || isec_id[e][f] == isec_id[a][b]) return 1;
    auto p1 = isecs[a][b].second;
}

void dfs(int i){
    if (sz(segs) == n) {

    }

    rep(j,0,n){
        // Can't visit
        if (vis[j] || isec_id[i][j]==-1) continue;

        // Check for self-intersections
        bool ok = true;
        rep(k,1,sz(segs)-1) {
            auto ipt = isecs[segs[k]][i].second;

            // Check if this is on both segments
            if (
                isec_id[segs[k]][i] == isec_id[segs[k]][segs[k+1]] ||
                isec_id[segs[k]][i] == isec_id[segs[k-1]][segs[k]] ||
            ) {
                ok = false;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    lines.resize(n);
    rep(i,0,n){
        cin >> lines[i].first.x >> lines[i].first.y >> lines[i].second.x >> lines[i].second.y;
    }
    rep(i,0,n){
        rep(j,i+1,n){
            isecs[j][i] = isecs[i][j] = lineInter(lines[i].first, lines[i].second, lines[j].first, lines[j].second);
            if (isecs[i][j].first == 0){
                isec_id[i][j] = isec_id[j][i] = -1;
                continue;
            }
            auto& p1 = isecs[i][j].second;
            int M = Mi;
            rep(k,0,sz(is_pts)){
                if ( (is_pts[k]-p1).dist2() < 1e-18 ) {
                    M = k;
                    break;
                }
            }
            isec_id[i][j] = isec_id[j][i] = M;
            if (M == Mi) {
                Mi++;
                is_pts.push_back(p1);
            }
        }
    }
    vis[0] = true;
    segs.push_back(0);
    dfs(0);
    cout << tot/2 << endl;
}