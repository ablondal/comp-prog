#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("help.in","r",stdin);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll m = 1e18;
		vi a(n);
		rep(i,0,n) cin >> a[i];
		ll tot = accumulate(all(a), 0LL);

		ll max1=0, max2=0;
		rep(i,0,sz(a)){
			if (a[i]>=max1){
				max2 = max1;
				max1 = a[i];
			} else if (a[i]>max2){
				max2 = a[i];
			}
		}

		ll tt = 0;
		rep(i,0,sz(a)-1){
			m = min( max(tot - tt - a[i] - a[i+1], tt), m );
			tt += a[i];
		}

		m = min(m, tot - max1 - max2);

		cout << m << endl;
	}
}