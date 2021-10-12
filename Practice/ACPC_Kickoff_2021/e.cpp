#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pair<int, int>> factor(int n){
	vector<pair<int, int>> ffs;
	for(int i=2; i*i <= n; ++i){
		if (n%i==0) {
			int a = 0;
			while(n%i==0){
				a++;
				n/=i;
			}
			ffs.push_back({i, a});
		}
	}
	if (n > 1){
		ffs.push_back({n, 1});
	}
	return ffs;
}

vector<pair<int, int>> lcm_v(vector<pair<int, int>> &a, vector<pair<int, int>> b){
	vector<pair<int, int>> ffs;
	int i=0, j=0;
	while(i<sz(a) || j<sz(b)){
		if (i==sz(a) || (j!= sz(b) && b[j].first < a[i].first) ){
			ffs.push_back(b[j]);
			j++;
		}else if (j==sz(b) || a[i].first < b[j].first){
			ffs.push_back(a[i]);
			i++;
		}else{
			ffs.push_back(max(a[i], b[j]));
			i++;
			j++;
		}
	}
	return ffs;
}

bool isprime(int n){
	if (n%2 == 0) return false;
	for(int i=3; i*i<=n; i+=2){
		if (n%i==0) return false;
	}
	return true;
}

int main() {

    freopen("lcm.in","r",stdin);
	int t;
	cin >> t;
	while(t--){
		ll n, l, r;
		cin >> n >> l >> r;
		vector<ll> a(n, 1);

		auto lc = factor(1);

		rep(i,0,n){
			cin >> a[i];
			lc = lcm_v(lc, factor(a[i]));
		}

		vi S;
		for(auto& f : lc){
			S.push_back(f.first);
			// cout << f.first << endl;
		}

		ll i;
		ll mingcd = 1e9;
		ll minx = 0;

		int M = 0;
		int Mi = 0;
		int x;
		for(x=r; x>=l; --x){
			ll n = x;
			for(auto& a : lc){
				int ii = 0;
				while(n%a.first==0 && ii<a.second){
					n /= a.first; ii++;
				}
				// while (n%a==0){
				// 	n /= a;
				// }
			}
			// cout << x << " " << n << endl;
			if (n > M){
				M = n;
				Mi = x;
			}
			if (M>=x) break;
		}
		cout << Mi << endl;

		// int x;
		// for(x=r; x>=l; --x){
		// 	if (isprime(x) && !S.count(x)) {
		// 		break;
		// 	}
		// }
		// if (x>=l){
		// 	cout << x << endl;
		// 	continue;
		// }

		// for(i=r; i>=l; --i){
		// 	// cout << i << endl;
		// 	ll g = 1;
		// 	rep(j,0,n){
		// 		// cout << a[j] << " " << (ll)i << " " << gcd(a[j], (ll)i) << endl;
		// 		g = lcm(g, gcd(a[j], i));
		// 	}
		// 	// if (g==1) cout << i << endl;
		// 	if ( i/g > minx / mingcd){
		// 		mingcd = g;
		// 		minx = i;
		// 	}
		// 	if (minx / mingcd >= i){
		// 		break;
		// 	}
			
		// }
		// cout << minx << endl;
	}
}