#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	vi a(n);
	vi s(n+2, 0);
	rep(i,0,n){
		cin >> a[i];
		if(i) s[i] = s[i-1] + a[i-1];
	}
	s[n] = a[n-1]+s[n-1];
	s[n+1] = 2e9+7;
	// rep(i,0,n+1){
	// 	cout << s[i] << " ";
	// }
	// cout << endl;
	int M = 0;
	rep(i,0,n){
		int l = upper_bound(all(s), s[i]+t) - s.begin() - 1;
		// cout << i << " " << l << endl;
		M = max(M, l-i);
	}
	cout << M << endl;
}