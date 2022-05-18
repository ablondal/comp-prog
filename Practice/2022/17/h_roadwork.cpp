#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define minim(a, b) a = min(a, b)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

vector<pii> E, W;
int DP[251][251][251][2] = {{{{0}}}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t >> n;
	set<int> S;
	rep(i,0,n){
		char a;
		int b, c;
		cin >> a >> b >> c;
		// cout << a << b << c;
		if (a == 'W'){
			W.push_back({b, b+c});
		} else {
			E.push_back({b, b+c});
		}
	}
	rep(i,0,251) rep(j,0,251) rep(k,0,251) rep(h,0,2) DP[i][j][k][h] = 1e9;

	DP[0][0][0][0] = DP[0][0][0][1] = 0;
	rep(e,0,sz(E)+1){
		rep(w,0,sz(W)+1){
			rep(g,0,e+w+1){
				// cout << e << " " << w << " " << g << endl;
				// cout << DP[e][w][g][0] << " " << DP[e][w][g][1] << endl;
				if (e<sz(E) && DP[e][w][g][0] <= E[e].second) {
					int go = max(E[e].first, DP[e][w][g][0]);
					minim(DP[e+1][w][g+1][0], go+3);
					minim(DP[e+1][w][g+1][1], go+t);
				} else {
					int go = DP[e][w][g][0];
					minim(DP[e+1][w][g][0], go+3);
					minim(DP[e+1][w][g][1], go+t);
				}

				if (w<sz(W) && DP[e][w][g][1] <= W[w].second) {
					int go = max(W[w].first, DP[e][w][g][1]);
					minim(DP[e][w+1][g+1][1], go+3);
					minim(DP[e][w+1][g+1][0], go+t);
				} else {
					int go = DP[e][w][g][1];
					minim(DP[e][w+1][g][1], go+3);
					minim(DP[e][w+1][g][0], go+t);
				}
			}
		}
	}
	int M = 0;
	rep(g,0,n+1){
		rep(h,0,2){
			if (DP[sz(E)][sz(W)][g][h] < 1e9) M = g;
		}
	}
	cout << n-M << endl;


}