//  International Collegiate Programming Contest (ACM-ICPC) World Finals 2016
/*
A large part of the world economy depends on oil,
which is why research into new methods for finding
and extracting oil is still active. Profits of oil
companies depend in part on how efficiently they can
drill for oil. The International Crude Petroleum
Consortium (ICPC) hopes that extensive computer
simulations will make it easier to determine how to
drill oil wells in the best possible way.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <numeric>
#include <utility>
using namespace std;
#define forn(i,k) for(int i=0; i<int(k); ++i)
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define pi acos(-1.0)
#define EPS 1e-9
// C++17 needed for numeric, or just make your own gcd, not too hard tbh
// Done, takes a loooong time to run, but ekes in
const int N = 2000;

typedef long long ll;
typedef pair<int, int> pt;
typedef pair<pt, int> ppt;
typedef struct _frac{
    ll n, d;
} frac;

int n, x, x0, x1, y;
vector <pt> pts; // x, y
vector <frac> fracs;
vector <int> pt_ref;
ll w[N];
bool vis[N];

frac m_f(ll n, ll d){
    ll g = max(1, gcd(n,d));
    int neg = 1;
    if(n<0) neg *= -1, n*=-1;
    if(d<0) neg *= -1, d*=-1;
    return frac({neg*n/g, d/g});
}

bool operator<(frac a, frac b){
    if (a.d==0){
        return false;
    }else if (b.d==0){
        return true;
    }
    return a.n*b.d < b.n*a.d;
}

bool operator==(frac a, frac b){
    return (a.n==b.n && a.d==b.d);
}

bool frac_cmp(int a, int b){
    return fracs[a]<fracs[b];
}

int main(){
    scanf("%d",&n);
    pt_ref.resize(2*n);
    fracs.resize(2*n);
    forn(i, n){
        scanf("%d%d%d",&x0,&x1,&y);
        pts.push_back({x0,y});
        pts.push_back({x1,y});
        w[i] = abs(x0-x1);
    }
    forn(i, 2*n) pt_ref[i] = i;
    forn(i, n) vis[i] = false;
    // For each endpoint, sort and shuffle
    ll max=0;
    ll cw;
    ll before;
    ll after;
    forn(bpt, 2*n){
        // printf("%d\n",bpt);
        forn(i, 2*n){
            // printf("%d\n",i);
            fracs[i] = m_f(pts[i].first-pts[bpt].first,pts[bpt].second-pts[i].second);
        }
        // printf("%d\n",bpt);
        sort(pt_ref.begin(), pt_ref.end(), frac_cmp);
        
        cw = w[bpt/2];
        max = max(max, cw);
        // printf("%d\n",bpt);
        int i=0;
        while(fracs[pt_ref[i]].d!=0){
            int j=i;
            int i_ref, j_ref;
            
            i_ref = pt_ref[i]/2;
            before = 0;
            after = 0;

            while(fracs[pt_ref[j]]==fracs[pt_ref[i]]){
                j_ref = pt_ref[j]/2;
                if(vis[j_ref]){
                    after -= w[j_ref];
                    vis[j_ref] = false;
                }else{
                    before += w[j_ref];
                    vis[j_ref] = true;
                }
                ++j;
            }
            i=j;
            cw += before;
            max = max(cw, max);
            cw += after;
        }
        // printf("%d\n",bpt);
    }
    printf("%lli\n",max);
}

















