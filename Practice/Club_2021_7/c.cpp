#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vi a(n), b(m);
	rep(i,0,n) cin >> a[i];
	rep(i,0,m) cin >> b[i];
	sort(all(a));
	sort(all(b));
	ll lo = -1, hi = 4e9+1;
	while(hi-lo>1){
		ll mid = (hi+lo)>>1;
		int ai=0, bi1=0, bi2=0;
		bool works = true;
		rep(i,0,n){
			while(bi1<m && b[bi1] <= a[i]+mid){
				bi1++;
			}
			while(bi2<m && b[bi2] < a[i]-mid){
				bi2++;
			}
			if (bi1==bi2){
				lo = mid+1;
				works = false;
				break;
			}
		}
		if (works) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << hi << endl;
}