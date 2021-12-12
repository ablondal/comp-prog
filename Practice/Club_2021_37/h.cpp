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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll n, c;
		cin >> n >> c;
		vector<ll> a(n), b(n);
		rep(i,0,n) cin >> a[i];
		rep(i,0,n-1) cin >> b[i];
		ll m = 1e18+7;
		ll days = 0;
		ll leftover = 0;
		for(int i=0; i<n; ++i){
			ll n_d = max(0LL, (c-leftover+a[i]-1)/a[i]);
			// cout << i << " " << days + n_d + 1 << endl;
			m = min(m, days + n_d + 1);
			if (i==n-1) break;
			ll exdays = max(0LL, (b[i]-leftover+a[i]-1)/a[i]);
			leftover = leftover + a[i]*exdays - b[i];
			days += exdays + 1;
		}
		cout << m-1 << endl;
	}
}