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

bitset<3000> DP;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	pii mx = {1000, 0};
	DP[0] = true;
	rep(i,0,n){
		DP |= (DP << a[i]);
	}
	rep(i,0,3000){
		if (DP[i]) {
			mx = min(mx, {abs(1000-i), -i});
		}
	}
	cout << -mx.second << endl;
}