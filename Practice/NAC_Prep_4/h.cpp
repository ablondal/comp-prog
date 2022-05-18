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
const int MX = 5e4+7;

char in_ival[MX] = {0};
ll note[MX] = {0};
ll ival[107][2] = {{0}};
ll starp[MX] = {0};
int DP[MX][107][2] = {{{0}}}; // Current note, how many intervals we saved up, and is this interval dead

int g_eq(ll pos){
    int lo = 0, hi = MX;
    while(hi-lo){
        int md = (hi+lo)/2;
        if (note[md] < pos) {
            lo = md+1;
        } else {
            hi = md;
        }
    }
    return hi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    rep(i,0,n) cin >> note[i];
    rep(i,n,MX) note[i] = 1e18;
    rep(i,0,p){
        cin >> ival[i][0] >> ival[i][1];
        // cout << g_eq(ival[i][0]) << " " << g_eq(ival[i][1]) << endl;
        rep(j,g_eq(ival[i][0]), g_eq(ival[i][1])){
            in_ival[j+1] = 1;
        }
    }
    rep(i,p,107){
        ival[i][0] = ival[i][1] = 1e18;
    }

    rep(i,0,n){
        if (in_ival[i]) {
            starp[i] = starp[i-1] + note[i] - note[i-1];
        }
        else {
            starp[i] = starp[i-1];
        }
        // cout << i << " " << starp[i] << endl;
    }
    // exit(0);

    rep(i,0,MX){
        rep(j,0,107){
            DP[i][j][0] = DP[i][j][1] = -1e7;
        }
    }

    int c_v = 0;

    int M = 0;

    DP[0][0][0] = 0;

    rep(i,1,n){
        if (ival[c_v][1] < note[i]) {
            c_v++;
            rep(k,0,103){
                DP[i][k][0] = max(DP[i][k][0], DP[i-1][k][1]);
            }
            rep(k,0,103){
                DP[i][k+1][0] = max(DP[i][k+1][0], DP[i-1][k][0]);
            }
        }
        rep(k,0,107){
            DP[i][k][0] = max(DP[i][k][0], DP[i-1][k][0]);
            DP[i][k][1] = max(DP[i][k][1], DP[i-1][k][1]);
        }
        rep(k,0,c_v+1){
            int pre = g_eq(ival[c_v-k][0]);
            if (pre > i) continue;
            ll c_pow = starp[i] - starp[pre];
            // cout << c_pow << endl;
            int to = g_eq(note[i] + c_pow);
            // cout << to << endl;
            if (to >= n) {
                // cout << "test " << DP[i][k][0] + n-i << endl;
                M = max(M, DP[i][k][0] + n-i);
            } else if (in_ival[to]) {
                DP[to][0][1] = max(DP[to][0][1], DP[i][k][0] + to-i);
            } else {
                DP[to][0][0] = max(DP[to][0][0], DP[i][k][0] + to-i);
            }
        }
        // rep(k,0,3){
        //     cout << i << " " << k << ": " << DP[i][k][0] << ", " << DP[i][k][1] << endl;
        // }
    }
    rep(k,0,107){
        M = max(M, DP[n][k][0]);
        M = max(M, DP[n][k][1]);
        M = max(M, DP[n-1][k][0]);
        M = max(M, DP[n-1][k][1]);
    }
    cout << M+n << endl;
}