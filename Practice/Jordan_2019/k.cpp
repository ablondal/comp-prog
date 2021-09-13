#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const double PI = acos(-1);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	ll tot = 0;
	rep(m,1,(1<<n)){
		ll e = 0;
		rep(j,0,n){
			if (m & (1<<j)) {
				e |= a[j];
			}
		}
		// cout << e << endl;
		tot += e;
	}
	cout << tot << endl;
}