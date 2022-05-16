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

// Minimize x + (d/(x+1))
// 1 - (d / (x+1)^2) = 0
// d / (x+1)^2 = 1
// (x+1)^2 = d
// x+1 = sqrt(d)

ll cost(ll d, ll x){
	return x + ceil((double)d / (x+1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll n, d;
		cin >> n >> d;
		
		double smn = sqrt(d) - 1;
		int a = floor(smn);
		int b = ceil(smn);

		int m = min(cost(d, a), cost(d, b));

		// cout << lo << endl;
		// cout << cost(d, lo) << endl;
		if (m<=n || n>=d){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}