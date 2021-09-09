#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll DP[20][7000] = {{0}};

ll t = 0;
unordered_map<ll, ll> ind;

inline ll get_ind(ll a, ll b) {
    return a*1e9 + b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, kk;
    cin >> n >> kk;

    vi d(n);
    rep(i,0,n) cin >> d[i];
    sort(all(d));

    rep(i,0,n-1) rep(j,i+1,n){
        ll aa = ind[get_ind(i,j)] = t++;
        // cout << i << " " << j << " " << get_ind(i,j) << " " << t << endl;
        DP[2][aa] = 1;
    }

    rep(k,0,n) rep(i,k+1,n) rep(j,i+1,n) {
        if (d[k]+d[i] >= d[j]){
            ll aa = ind[get_ind(k,i)];
            ll bb = ind[get_ind(i,j)];
            rep(L,2,kk){
                DP[L+1][bb] += DP[L][aa];
                // cout << L+1 << " " << bb << " " << DP[L+1][bb] << endl;
            }
        }
    }

    ll tot = 0;
    rep(i,0,7000){
        tot += DP[kk][i];
    }
    cout << tot << endl;
}