#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, p, q, s;
    cin >> n >> p >> q >> s;

    vi P(p), Q(q);
    rep(i,0,p) cin >> P[i];
    rep(i,0,q) cin >> Q[i];
    sort(all(P)); sort(all(Q));

    ll lo = 0, hi = 2e9+1;
    ll orghi = hi;
    while(hi-lo){
        ll md = (hi+lo)/2;

        cout << md << endl;

        set<ll> S(all(Q));
        int ct = 0;
        // for(int i=p-1; i>=0; --i){
        //     auto it = S.upper_bound(min(P[i]+md, s-P[i]));
        //     if (it != S.begin()){
        //         it--;
        //         if (*it >= P[i]-md) {
        //             ct++;
        //             cout << P[i] << " " << *it << endl;
        //             S.erase(it);
        //         }
        //     }
        // }
        rep(i,0,p){
            auto it = S.upper_bound(min(P[i]+md, s-P[i]));
            if (it != S.begin()) {
                it--;
                if (*it >= P[i]-md) {
                    ct++;
                    cout << P[i] << " " << *it << endl;
                    S.erase(it);
                }
            }
        }

        if (ct < n){
            lo = md + 1;
        } else {
            hi = md;
        }
    }

    cout << (orghi == hi ? -1 : lo) << endl;

}