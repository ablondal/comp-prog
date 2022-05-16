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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int x, n;
		cin >> n >> x;
		vector<ll> a(n);
		ll m = 1e9, M = 0;
		ll tot = 0;
		ll mM = 1e9, mm = 1e9;
		rep(i,0,n){
			cin >> a[i];
			m = min(m, a[i]);
			M = max(M, a[i]);
			if (i){
				tot += abs(a[i]-a[i-1]);
				
				if (a[i] >= x || a[i-1] >= x) mM = 0;
				else mM = min(mM, 2*min(x-a[i], x-a[i-1]));

				if (a[i] == 1 || a[i-1] == 1) mm = 0;
				else mm = min(mm, 2*min(a[i]-1, a[i-1]-1));
			} else {
				mm = min(mm, a[i]-1);
				if (a[i] >= x) mM = 0;
				else mM = min(mM, x-a[i]);
			}
		}
		if (a[n-1] > x) mM = 0;
		else mM = min(mM, x-a[n-1]);
		mm = min(mm, a[n-1]-1);
		cout << tot + mm + mM << endl;

	}
}