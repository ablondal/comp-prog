#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e6+7;
const ll MOD = 998244353;
ll DP[MX] = {0};

ll binpow(ll a, ll x){
    ll r = 1;
    while(x){
        if (x & 1){
            r *= a;
            r %= MOD;
        }
        a = (a*a)%MOD;
        x >>= 1;
    }
    return r;
}

vector<ll> facs(ll a){
    if (a == 1) return {};
    vector<ll> res;
    for(ll f = 1; f*f <= a; ++f){
        if (a%f == 0) res.push_back(f);
    }
    return res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int m, k;
    cin >> m >> k;
    DP[0] = 1;
    ll sum = 1;
    rep(i,1,k+1){
        DP[i] = (MOD + binpow((2*i + 1), m) - binpow((2*i - 1), m)) % MOD;
        // DP[i] = (DP[i] + MOD - sum) % MOD;
        for(auto f : facs(i)) {
            DP[i] = (DP[i] + MOD - DP[f]) % MOD;
        }
        sum = (sum + DP[i]) % MOD;
    }
    cout << sum << endl;
}