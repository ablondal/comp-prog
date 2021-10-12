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

vll a, b;
ll n, m;

pair<ll, ll> tryy(ll min_trick){
	ll num_tricks = 0;
	ll tot_pts = 0;
	rep(i,0,n){
		if (a[i] < min_trick) continue;
		ll n_t = ( (a[i]-min_trick)/b[i] ) + 1;
		ll pts = (a[i] + a[i] - (n_t*b[i]) + b[i]) * n_t;
		pts /= 2;
		num_tricks += n_t;
		tot_pts += pts;
	}
	return {num_tricks, tot_pts};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// ll n, m;
	cin >> n >> m;
	// vll a(n), b(n);
	a.resize(n);
	b.resize(n);
	rep(i,0,n) cin >> a[i];
	rep(i,0,n) cin >> b[i];
	auto alltricks = tryy(2);
	ll unone = alltricks.first;
	
	if (unone <= m) {
		cout << alltricks.second + m - unone << endl;
	} else {
		int lo = 2, hi = 1e9+2;
		while(hi-lo>1){
			int md = (hi+lo)/2;
			auto tt = tryy(md);
			if (tt.first >= m) lo = md;
			else hi = md;
		}
		auto tt = tryy(lo);
		cout << tt.second - (lo * (tt.first - m)) << endl;
	}
}