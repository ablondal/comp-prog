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
const int MOD = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	rep(T, 1, t+1){
		int n, k;
		cin >> n;
		if (n == -1) break;
		cin >> k;
		
		int tot = 0;

		if (n <= k){
			rep(i,1,n+1){
				cout << "T " << i << endl;
				int r, a;
				cin >> r >> a;
				tot += a;
			}
			tot /= 2;
			cout << "E " << tot << endl;
		} else {
			int r, a, b=0;
			rep(i,0,k){
				cout << "T " << b+1 << endl;
				cin >> r >> a;
				tot += a;
				b = (b + MOD) % n;
			}
			double tt = (double)tot * ((double)n / k);
			tt /= 2;
			cout << "E " << round(tt) << endl;
		}
	}
}