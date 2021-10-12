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

vector<pair<ll, int>> factor2(ll n){
	vector<pair<ll, int>> ans;
	for(ll i=2; i*i<=n; ++i){
		int ct = 0;
		while(n % i == 0){
			// ans.push_back(i);
			n /= i;
			ct++;
		}
		if (ct) {
			ans.push_back({i, 2*ct});
		}
	}
	if (n > 1) {
		ans.push_back({n, 2});
	}
	// cout << endl;
	return ans;
}

ll get_nth_divisor(int n, vector<pair<ll, int>>& facs){
	ll d = 1;
	for (int i=sz(facs)-1; i>=0; --i) {
		auto& fac = facs[i];
		int a = n % (fac.second+1);
		ll p = 1;
		rep(i,0,a) p *= fac.first;

		d *= p;
		n /= (fac.second+1);
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll k;
	cin >> k;
	auto ffs = factor2(k);
	
	vector<pair<ll, ll>> ans;

	int n = 1;
	for(int i=0; i<sz(ffs); ++i){
		auto& fac = ffs[i];
		n *= (fac.second+1);
		// if (i) fac.second = (fac.second+1) * ffs[i-1].second;
		// else fac.second = fac.second+1;
	}
	cout << n << endl;
	rep(i,0,n){
		ll nn = get_nth_divisor(i, ffs);
		ll a = k + nn;
		ll b = (k*k)/nn + k;
		// cout << get_nth_divisor(i, ffs) << endl;
		cout << a << " " << b << endl;
	}
}