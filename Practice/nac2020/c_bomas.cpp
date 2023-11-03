#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double eps = 1e-9;
const int MX = 2e5 + 7;
double globalX;

struct half_boma{
    int idex;
    double x, y, r;
    int mul;
    double y_at(double X){
        return y + mul*sqrt(r*r - (X-x)*(X-x) + eps);
    }
};

half_boma hbs[2*MX];

struct hb_pt{
    int idex;
    bool operator<(const hb_pt &b) const {
        return hbs[idex].y_at(globalX) < hbs[b.idex].y_at(globalX);
    }
};

set<hb_pt> S;
bool isQ[MX] = {0};
int p[MX] = {0};
int DP[MX][2] = {{0}};
vi adj[MX];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, q;
    cin >> n >> q;
    vector<pair<int, pii>> sweep;
    rep(i,0,n){
        double x, y, r;
        cin >> x >> y >> r;
        hbs[2*i] = {i, x, y, r, 1};
        hbs[2*i+1] = {i, x, y, r, -1};
        sweep.push_back({x-r, {2*i, 1}});
        sweep.push_back({x+r, {2*i, -1}});
        sweep.push_back({x-r, {2*i+1, 1}});
        sweep.push_back({x+r, {2*i+1, -1}});
    }
    rep(i,0,q){
        double x, y, r;
        cin >> x >> y >> r;
        hbs[2*i+2*n] = {n+i, x, y, r, 1};
        hbs[2*i+1+2*n] = {n+i, x, y, r, -1};
        sweep.push_back({x-r, {2*(i+n), 1}});
        sweep.push_back({x+r, {2*(i+n), -1}});
        sweep.push_back({x-r, {2*(i+n)+1, 1}});
        sweep.push_back({x+r, {2*(i+n)+1, -1}});
        isQ[n+i] = true;
    }

}