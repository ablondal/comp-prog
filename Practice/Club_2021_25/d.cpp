#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll M = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	vector<int> ff(k, 500);
	rep(i,0,n){
		cin >> a[i];
		rep(j,0,k){
			if (ff[j]==500 && (a[i]>>j)&1 ){
				ff[j] = i+1;
			}
		}
	}
	ll tot = 0;
	int mult = 1;
	sort(all(ff));
	rep(i,0,k){
		if (ff[i]==500) break;
		ll aa = (1LL<<(k-i-1));
		aa %= M;
		tot += (ff[i])*aa;
		tot %= M;
	}
	cout << tot << endl;
}