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

ll mv_s(ll a){
	ll i = 10;
	ll vis = 0;
	ll siz = 0;
	ll p = 1;
	while(i<=a){
		siz += (i-vis-1) * p;
		vis += (i-vis-1);
		p++;
		i*=10;
	}
	siz += (a - vis)*p;
	return siz;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	rep(T,0,q){
		ll k;
		cin >> k;
		ll lo = 0, hi = 1e18;
		while(hi - lo > 1){
			// cout << hi << " " << lo << endl;
			ll md = hi/2 + lo/2 + (hi & lo & 1);
			if (mv_s(md) < k) lo = md;
			else hi = md;
		}
		// cout << lo << endl;
		ll s = k-mv_s(lo);
		string lets;
		while(hi){
			lets.push_back('0'+ (hi%10));
			hi /= 10;
		}
		reverse(all(lets));
		cout << lets[s-1] << endl;
	}
}