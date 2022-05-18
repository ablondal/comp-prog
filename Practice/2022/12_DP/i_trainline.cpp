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
const int MAXN = 1e5+6;
const int D = 30;

int n, k;
int pop[MAXN];
ll d[MAXN];
double aft[MAXN], bef[MAXN];
double btwn[MAXN][D+2];

double DP[MAXN];
int p[MAXN];

pair<int, double> optimize(double cost){
	// cout << "cost: " << cost << endl;

	rep(i,0,n) {
		DP[i] = bef[i] + pop[i] + aft[i] - cost;
		p[i] = -1;
	}

	int mp = -1;
	double m = 0;
	double prev = 0;
	double prevp = -1;

	rep(i,0,n){
		if (prev + bef[i] + pop[i] + aft[i] - cost > DP[i]) {
			p[i] = prevp;
			DP[i] = prev + bef[i] + pop[i] + aft[i] - cost;
		}

		rep(j, i-D, i) {
			if (j >= 0) {
				if (DP[j] - aft[j] + btwn[j][i-j] + pop[i] + aft[i] - cost > DP[i]) {
					p[i] = j;
					DP[i] = DP[j] - aft[j] + btwn[j][i-j] + pop[i] + aft[i] - cost;
				}
			}
		}

		if (i-D >= 0 && DP[i-D] > prev){
			prev = DP[i-D];
			prevp = i-D;
		}
		
		if (DP[i] > m){
			m = DP[i];
			mp = i;
		}

		// cout << i << " " << DP[i] << endl;
	}

	int pp = mp;
	int ct = 0;
	while(pp != -1){
		// cout << pp << endl;
		ct++;
		pp = p[pp];
	}

	return {ct, m};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	rep(i,0,n) cin >> pop[i] >> d[i];

	if (k >= n){
		double tot = 0;
		rep(i,0,n) tot += pop[i];
		cout << setprecision(20) << tot << endl;
		return 0;
	}

	rep(i,0,n){
		aft[i] = bef[i] = 0;
		rep(j,i+1,i+D){
			if (j < n){
				aft[i] += pop[j] * pow(0.5, d[j]-d[i]);
			}
		}
		rep(j, i-D, i){
			if (j>=0){
				bef[i] += pop[j] * pow(0.5, d[i]-d[j]);
			}
		}
		rep(j,1,D+2){
			btwn[i][j] = 0;
			rep(k,1,j){
				btwn[i][j] += pop[i+k] * pow(0.5, min(d[i+j]-d[i+k], d[i+k]-d[i]));
			}
		}
	}

	double lo = 0, hi = 1000;
	double ans = 0;
	while(hi-lo > 1e-12){
		// cout << lo << " " << hi << endl;
		double md = (hi + lo) / 2;
		auto res = optimize(md);
		// cout << res.first << " and " << res.second << endl;
		// ans = res.second + md*k;
		// cout << ans << endl;
		if (res.first == k){
			ans = res.second + md*k;
			break;
		} else if (res.first > k){
			lo = md;
		} else {
			hi = md;
		}
	}
	// cout << lo << endl;
	if (ans == 0) {
		auto res = optimize(lo);
		// cout << res.first << " " << res.second << endl;
		ans = res.second + k*lo;
	}

	cout << setprecision(20) << ans << endl;
}