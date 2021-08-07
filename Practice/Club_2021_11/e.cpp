#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9+7;
const int MAXN = 2e5+7;
const ll MOD = 1e9+7;
vi adj[200007];
char V[200007] = {0};

unordered_set<ll, ll> M;

ll fac[MAXN];
ll ifac[MAXN];


ll choose(int n, int r){
	ll res = fac[n];
	res = (res*ifac[r])%MOD;
	res = (res*ifac[n-r])%MOD;
	return res;
}

ll inv(ll a){
	ll m = MOD-2;
	ll res = 1;
	while(m>0){
		if (m & 1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		m = (m>>1);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, t;
	scanf("%d", &t);

	fac[0] = 1;
	fac[1] = 1;
	rep(i,2,MAXN){
		fac[i] = fac[i-1]*i;
		fac[i] %= MOD;
	}
	ifac[MAXN-1] = inv(fac[MAXN-1]);
	for(int i=MAXN-1; i>0; --i){
		ifac[i-1] = ifac[i]*i;
		ifac[i-1] %= MOD;
	}


	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		vector<pair<int, int>> pts;
		// set<int> xc, yc;
		// xc.insert(0);
		// set<pair<int, int>> blk;
		rep(i,0,k){
			int a,b;
			scanf("%d%d", &a,&b);
			pts.push_back({a,b});
		}
		pts.push_back({n,m});
		sort(all(pts));
		vector<ll> re(sz(pts));
		rep(i,0,k+1){
			re[i] = choose(pts[i].first+pts[i].second-2, pts[i].first-1);
		}
		rep(i,0,k+1){
			rep(j,i+1,k+1){
				// printf("%d %d\n", i, j);
				int x1 = pts[i].first, x2=pts[j].first, y1=pts[i].second, y2=pts[j].second;
				// printf("%d,%d to %d,%d\n",x1,y1,x2,y2);
				if (x2 < x1 || y2 < y1) continue;
				// Now we simply get rid of all paths from there to here
				re[j] -= re[i] * choose(x2+y2-x1-y1, x2-x1);
				re[j] = (re[j] % MOD) + MOD;
				re[j] %= MOD;
				// printf("%d,%d to %d,%d: got rid of %lld\n", x1,y1,x2,y2,choose(x2+y2-x1-y1, x2-x1));
			}
		}
		printf("%lld\n", re[k]);
	}
	
}