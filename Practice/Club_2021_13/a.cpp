#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Actually just a hack

ll add(ll a, ll b){
	vi c(20, 0);
	int i=0;
	while(a != 0 || b != 0){
		// c *= 10;
		c[i] = (a%10 + b%10)%10;
		++i;
		a /= 10;
		b /= 10;
		// printf("%d\n", i);
	}
	// cout << "out at " << i << endl;
	ll ans = 0;
	for(int i=18; i>=0; --i){
		ans *= 10;
		ans += c[i];
	}
	return ans;
}

ll inv(ll a){
	vi c(20, 0);
	int i=0;
	while(a != 0){
		// c *= 10;
		c[i] = (10- (a%10));
		++i;
		a /= 10;
		// b /= 10;
		// printf("%d\n", i);
	}
	// cout << "out at " << i << endl;
	ll ans = 0;
	for(int i=18; i>=0; --i){
		ans *= 10;
		ans += c[i];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	vector<long long> ns(t);
	rep(i,0,t) cin >> ns[i];
	bool ismax = false;
	rep(i,0,t) if (ns[i] == 1e18) ismax = true;
	sort(all(ns));
	ll M = 0;
	ll m = 1e18+1;
	rep(i,0,t){
		ll currnum = 1e18-1-ns[i];
		int lo = 0;
		int hi = t;
		while(hi-lo>1){
			int mid = (hi+lo)>>1;
			if (ns[mid]<=currnum){
				lo = mid;
			}else{
				hi = mid;
			}
		}
		ll big = 0;
		for(int j=-2; j<3; ++j){
			if ( (lo+j+t)%t != i){
				// cout << (lo+j+t)%t << endl;
				big = max(big, add(ns[i], ns[(lo+j+t)%t]));
			}
		}
		M = max(M, big);
	}

	if (ismax){
		M = (ll)1e18 + ns[t-2];
	}

	rep(i,0,t){
		ll currnum = inv(ns[i]);
		// int b = ns[i];
		// while(b){

		// }
		int lo = 0;
		int hi = t;
		while(hi-lo>1){
			int mid = (hi+lo)>>1;
			if (ns[mid]<=currnum){
				lo = mid;
			}else{
				hi = mid;
			}
		}
		ll sm = 1e18+2;
		for(int j=-2; j<3; ++j){
			if ( (lo+j+t)%t != i){
				// cout << (lo+j+t)%t << endl;
				sm = min(sm, add(ns[i], ns[(lo+j+t)%t]));
			}
		}
		m = min(m, sm);
	}
	cout << m << " "<< M << endl;
}