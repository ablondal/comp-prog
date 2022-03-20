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
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i,0,n) cin >> a[i];
	ll tot = 0;
	ll n1 = 0;
	ll n2 = 0;
	ll MOD = 1e9+7;
	rep(i,0,n){
		if (a[i]==1){
			n1++;
		} else if (a[i]==2) {
			n2 += (n2 + n1);
			n2 %= MOD;
		} else {
			tot += n2;
			tot %= MOD;
		}
		// cout << n1 << " " << n2 << " " << tot << endl;
	}
	cout << tot << endl;
}