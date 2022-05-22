#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi pi(const string& s){
    vi p(sz(s));
    rep(i,1,sz(s)) {
        int g = p[i-1];
        while(g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}

vi match (const string& s, const string& pat) {
    vi p = pi(pat + '\0' + s), res;
    rep(i,sz(p)-sz(s), sz(p))
        if (p[i] == sz(pat)) res.push_back(i-2*sz(pat));
    return res;
}

int M = 1e9, n;
void minim(int a, int b, int c){
    int ab = abs(a-b), bc = abs(b-c), ac = abs(a-c);
    M = min(M, min(ab, n-ab)+min(ac, n-ac));
    M = min(M, min(ab, n-ab)+min(bc, n-bc));
    M = min(M, min(bc, n-bc)+min(ac, n-ac));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string x, y, z;
    cin >> x >> y >> z;
    n = sz(x);

    rep(i,0,n){
        x[i] -= 'A'-1;
        y[i] -= 'A'-1;
        z[i] -= 'A'-1;
    }

    z = z+z;
    z.pop_back();

    rep(i,0,n){
        bool w = true;
        rep(j,0,n){
            if (x[j] == y[(i+j)%n]) {
                w = false;
                break;
            }
        }
        if (w){
            string targ(n, 0);
            rep(j,0,n) targ[j] = x[j] ^ y[(i+j)%n];
            auto ms = match(z, targ);
            for(auto m : ms){
                minim(0, i, m);
            }
        }
    }
    cout << (M == 1e9 ? -1 : M) << endl;

}