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
	int t;
	cin >> t;
	while(t--){
		ll n, x;
		cin >> n >> x;
		vector<ll> a(n), b(n);
		rep(i,0,n){
			cin >> a[i];	
		} 
		sort(all(a));
		rep(i,0,n){
			b[i] = a[i];
			if (i) b[i] += b[i-1];
		}
		ll tot = 0;
		ll last_t = 0;
		for(int i = n-1; i>=0; --i){
			if (b[i] + (i+1)*last_t > x) continue;
			ll diff = x - (b[i] + (i+1)*last_t);
			ll num = 1 + (diff / (i+1));
			tot += (i+1)*num;
			last_t += num;
		}
		cout << tot << endl;
	}
}