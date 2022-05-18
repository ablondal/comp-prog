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
	ll n, m, k;
	cin >> n >> m >> k;
	ll i = 0;
	ll tot = 0;
	while(i < m && (tot + n-i <= k)){
		tot += n-i;
		i++;
	}
	if (k < n || (i==m && tot < k) ){
		cout << -1 << endl;
		exit(0);
	}
	vi ans;
	int a = 0, b = -1;
	ll d = (k - tot);
	// cout << d << endl;
	rep(j,0,n){
		if (a == b) a = (a+1) % (i+1);
		ans.push_back(a+1);
		a = (a+1)%(i+1);
		if (j+1 == d+i) {
			b = a;
		}
	}
	rep(j,0,n){
		cout << ans[j] << " ";
	}
	cout << endl;
}