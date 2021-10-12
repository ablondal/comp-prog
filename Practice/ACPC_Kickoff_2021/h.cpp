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
    freopen("bad-memes.in","r",stdin);
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> a(n), ac(n+1, 0);
		rep(i,0,n) cin >> a[i];
		rep(i,1,n+1) ac[i] = ac[i-1] + a[i-1];
		ll m = -1e11;
		int mx = -1;

		rep(x, 1, n+1){
			ll M = 1e11;
			for(int i=0; i<n; i+=x){
				ll curriq;
				if (i+x>n){
					curriq = ac[n] - ac[i];
				} else {
					curriq = ac[i+x] - ac[i];
				}
				M = min(M, curriq);
			}
			if (M > m){
				mx = x;
				m = M;
			}
		}
		cout << m << endl;
	}
}