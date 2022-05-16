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
typedef vector<vll> mat;
const ll MAX = 507;

int findlo(vi& a, int pos){
	int lo = 0, hi = sz(a);
	while(hi-lo>1){
		int md = (hi+lo)/2;
		if (a[md] < pos) lo = md;
		else hi = md;
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c, t1, t2;
	cin >> n >> c >> t1 >> t2;
	vi a(n+1);
	a[0] = -1e6;
	rep(i,1,n+1){
		cin >> a[i];
		if (i-1) a[i] -= a[1];
	}
	a[1] = 0;
	// rep(i,1,n+1) cout << a[i] << endl;
	int m = 1e7;
	rep(i,0,n){
		vi DP(n+1,0);

		rep(j,1,n+1){
			// DP[j] = DP[]
			int l1 = findlo(a, a[j]-t1);
			int l2 = findlo(a, a[j]-t2);
			DP[j] = min(DP[l1]+t1, DP[l2]+t2);
			// cout << j << " " << DP[j] << " " << l1 << " " << l2 << endl;
		}
		m = min(m, DP[n]);


		a.push_back(c);
		a.erase(a.begin()+1);
		int b = a[1];
		rep(i,1,n+1) a[i] -= b;
	}
	cout << m << endl;
}