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
const ll mod = 998244353;
const int ns = 13;

ll DP[1<<ns][ns][12][12] = {{{{0}}}};
ll DPa[ns+1][12][12] = {{{0}}};
ll DPb[2*ns+1][12][12][12] = {{{{0}}}};

ll inv(ll a){
	ll x = mod-2;
	ll r = 1;
	while(x){
		if (x & 1) r = (r*a)%mod;
		a = (a*a)%mod;
		x >>= 1;
	}
	return r;
}

ll choose(ll c, ll r){
	ll top = 1;
	ll bot = 1;
	rep(i,0,r){
		top = (top * (c-i)) % mod;
		bot = (bot * (i+1)) % mod;
	}
	return (top * inv(bot)) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	rep(i,0,ns){
		DP[1<<i][i][0][0] = 1;
	}

	rep(mask, 1, 1<<ns){
		bool ct = false;
		rep(i,1,ns+1){
			if (mask == (1<<i)-1) ct=true;
		}
		if (ct) continue;
		rep(prev, 0, ns){
			if (!(mask & (1<<prev))) continue;
			rep(nxt, 0, ns){
				if (mask & (1<<nxt)) continue;
				int invs = 0;
				rep(j,nxt+1,ns){
					if (mask & (1<<j)) invs++;
				}
				int rev = (nxt < prev);
				rep(k,0,12-invs){
					rep(x,0,12-rev){
						DP[mask | (1<<nxt)][nxt][k+invs][x+rev] += DP[mask][prev][k][x];
						DP[mask | (1<<nxt)][nxt][k+invs][x+rev] %= mod;
					}
				}
			}
		}
	}

	rep(i,1,ns+1){
		rep(k,1,12){
			rep(x,1,12){
				rep(nxt,0,ns){
					// cout << (1<<i)-1 << " " << nxt << " " << k << " " << x << " " << DP[(1<<i)-1][nxt][k][x] << endl;
					DPa[i][k][x] += DP[(1<<i)-1][nxt][k][x];
					DPa[i][k][x] %= mod;
				}
				DPb[i][k][x][1] = DPa[i][k][x];
				// if (DPa[i][k][x] == 0) continue;
				// cout << i << " " << k << " " << x << ": " << DPa[i][k][x] << endl;
			}
		}
	}

	rep(i,1,2*ns+1){
		rep(l,2,12){
			rep(k,1,12){
				rep(x,1,12){
					rep(j,1,i){
						rep(k2,1,k){
							rep(x2,1,x){
								DPb[i][k][x][l] += (DPb[j][k2][x2][l-1] * DPb[i-j][k-k2][x-x2][1]) % mod;
								DPb[i][k][x][l] %= mod;
							}
						}
					}
				}
			}
		}
	}

	int t;
	cin >> t;
	while(t--){
		int n,k,x;
		cin >> n >> k >> x;
		ll tot = 0;
		rep(l,1,12) {
			rep(i,1,min(2*ns+1, n+1)){
				// cout << i << " " << l << " " << DPc[i][k][x][l] << endl;
				// cout << DPb[i][k][x] << endl;
				tot += (DPb[i][k][x][l] * choose(n-i+l, l));
				tot %= mod;
			}
		}
		cout << tot << endl;
	}



}