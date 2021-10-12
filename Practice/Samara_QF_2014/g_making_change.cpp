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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, s;
	cin >> n >> s;
	vector<ll> a(n+1, 1);
	rep(i, 1, n+1) {
		cin >> a[i];
		a[i] = a[i-1] * a[i];
		if (a[i] > 1e9+7) a[i] = 1e9+7;
	}
	ll tot = 0;
	for(int i=n; i>=0; --i){
		tot += (s / a[i]);
		s %= a[i];
	}
	cout << tot << endl;
}