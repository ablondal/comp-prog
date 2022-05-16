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

// eggs used, throws made
ll DP[33][33] = {{0}};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	rep(i,1,33){
		DP[1][i] = i;
	}
	rep(i,2,33){
		rep(j,1,33){
			DP[i][j] = DP[i][j-1] + DP[i-1][j-1] + 1;
		}
	}

	// rep(i,0,33){
	// 	rep(j,0,33){
	// 		cout << DP[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		ll m = 33;
		rep(i,1,33){
			rep(j,1,33){
				if (i <= k && DP[i][j] >= n){
					m = min(m, (ll)j);
				}
			}
		}
		// rep(i,1,33){
		// 	if (DP[k][i] >= n){
		// 		m = i;
		// 		break;
		// 	}
		// }
		if (m <= 32){
			cout << m << endl;
		} else {
			cout << "Impossible" << endl;
		}

		// cout << (m > 32 ? "Impossible" : )
	}
}