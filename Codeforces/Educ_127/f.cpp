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
const int ns = 23;

ll DPa[ns][ns][12][12] = {{{{0}}}};
ll DPb[ns][12][12] = {{{0}}};
ll DPc[ns][12][12][12] = {{{0}}};

ll fac(ll a){
	ll r = 1;
	while(a){
		r = (r*a)%mod;
		a--;
	}
	return r;
}

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
	DPa[1][1][0][0] = 1;
	rep(i,2,ns){
		rep(af, 1, i+1){
			rep(k, 0, 12){
				if (k + (i-af) > 11) continue;
				rep(b4, 1, i){
					rep(x, 0, i-1){
						DPa[i][af][k+(i-af)][x + (af <= b4)] += DPa[i-1][b4][k][x];
						DPa[i][af][k+(i-af)][x + (af <= b4)] %= mod;
					}
				}
			}
		}
	}
	rep(i,1,ns){
		rep(k,0,12){
			rep(x,0,12){
				// DPb[i][k][x] = 0;
				rep(af,1,i+1){
					DPb[i][k][x] += DPa[i][af][k][x];
					DPb[i][k][x] %= mod;
				}
				rep(j,i+1,ns){
					DPb[j][k][x] -= (1+j-i)*DPb[i][k][x];
					DPb[j][k][x] = (DPb[j][k][x]%mod + mod) % mod;
				}
			}
		}
	}
	rep(i,1,ns){
		rep(k,1,12){
			rep(x,1,12){
				// DPc[i][k][x][1] = DPb[i][k][x];
				ll st = 0;
				for(int l=11; l>=2; --l){
					rep(j,1,i){
						rep(k2,1,k){
							rep(x2,1,x){
								DPc[i][k][x][l] += (DPc[j][k2][x2][l-1] * DPc[i-j][k-k2][x-x2][1]);
								DPc[i][k][x][l] %= mod;
							}
						}
					}
					rep(j,i+1,ns){
						DPc[j][k][x][l] -= DPc[i][k][x][l] * choose(j-i+l-2, l-2);
						DPc[j][k][x][l] %= mod;
					}
					// DPc[i][k][x][l] = (DPc[i][k][x][l] * inv(fac(l))) % mod;
					st += DPc[i][k][x][l];
					st %= mod;
				}
				DPc[i][k][x][1] = (((DPb[i][k][x] - st) % mod) + mod) % mod;
				if (DPc[i][k][x][1] != 0 && i<9){
					cout << i << " " << k << " " << x << ": " << DPc[i][k][x][1] << endl;
				}
				// rep(j,i+1,ns){
				// 	DPb[j][k][x] -= (1+j-i)*DPc[i][k][x][1];
				// 	DPb[j][k][x] = (DPb[j][k][x]%mod + mod) % mod;
				// }
			}
		}
	}

	map<tuple<int, int, int>, vector<vi> > M;
	vi a = {1, 2, 3, 4, 5};
	do {
		int n_inv = 0, n_nxt = 0, n_seg = 0;
		set<int> B;
		rep(i,0,sz(a)){
			B.insert(a[i]);
			if (sz(B) == 1 && *B.begin() == i+1) goto n_step;
			auto it = B.end();
			it--;
			if (*B.begin() == i+2-sz(B) && *it == i+1) {
				n_seg++;
				B.clear();
			}
		}
		rep(i,0,sz(a)-1){
			if (a[i]>a[i+1]) n_nxt++;
		}
		rep(i,0,sz(a)){
			rep(j,i+1,sz(a)){
				if (a[i] > a[j]) n_inv++;
			}
		}
		M[{n_inv, n_nxt, n_seg}].push_back(a);
		n_step:;
	} while (next_permutation(all(a)));
	rep(k,1,12){
		rep(x,1,12){
			rep(l,1,12){
				if (DPc[sz(a)][k][x][l] == 0) continue;
				cout << sz(a) << " " << k << " " << x << " " << l << ": " << DPc[sz(a)][k][x][l] << endl;
				cout << M[{k,x,l}].size() << endl;
			}
		}
	}

	ll tot = 0;
	/* 163316 11 7 */
	int n = 7;
	int k = 3;
	int x = 1;
	rep(l,1,12) {
		rep(i,1,min(ns, n+1)){
			// cout << i << " " << l << " " << DPc[i][k][x][l] << endl;
			// cout << DPb[i][k][x] << endl;
			tot += (DPc[i][k][x][l] * choose(n-i+l, l));
			tot %= mod;
		}
	}
	cout << tot << endl;


	exit(0);

	int t;
	cin >> t;
	while(t--){
		ll n, k, x;
		cin >> n >> k >> x;
		if (x > k){
			cout << 0 << endl;
			continue;
		}
	}
}