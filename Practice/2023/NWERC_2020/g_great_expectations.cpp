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
const int MAXN = 53;

int t[MAXN], d[MAXN];
double p[MAXN];

// double prob[6007][53] = {{0}}; // Probability that you make it thru
// [t][i] Given that you have just reached point i in the run spending t extra time

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r, m;
	cin >> n >> r >> m;
	int slack = r-n;
	rep(i,0,m) cin >> t[i] >> p[i] >> d[i];
	t[m] = n;

	vector<vector<double>> expec(slack + 1007, vector<double>(m+3, 0));

	rep(j,0,m+1){
		rep(i,slack,slack+1007){
			expec[i][j] = 1e18;
		}
	}

	double lo = n, hi = 100000 * r;
	while( (hi - lo) / lo > 1e-8){
		double md = lo + (hi-lo)/2;

		// Recalculate expected time taken

		for(int trick=m-1; trick >= 0; trick--){
			rep(tt, 0, slack) {
				if (tt + d[trick] >= slack) {
					expec[tt][trick] = p[trick]*(expec[tt][trick+1] + t[trick+1]-t[trick])
						+ (1-p[trick])*md;
				} else {
					expec[tt][trick] = p[trick]*(expec[tt][trick+1] + t[trick+1]-t[trick])
					+ (1-p[trick]) * min(
						md,
						(expec[tt+d[trick]][trick+1] + t[trick+1]-t[trick] + d[trick])
					);
				}
			}
		}
		expec[0][0] += t[0]; // Time to get to first trick
		// cout << md << " " << expec[0][0] << endl;

		if (expec[0][0] > md) lo = md;
		else hi = md;
	}
	cout << setprecision(18) << lo << endl;

}