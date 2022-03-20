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

unordered_set<ll> D;

bool factor(unordered_map<int, int> &a, int n){
	// map<int, int> a;
	bool m = false;
	for(int i=2; i*i <= n; ++i){
		if (n%i==0){
			int ct = 0;
			do{
				ct++;
				n/=i;
			}while(n%i==0);
			if ( !a.count(i) || ct > a[i] ){
				a[i] = ct;
				m = true;
			}
		}
	}
	if (n != 1 && (!a.count(n))){
		a[n] = 1;
		m = true;
	}

	return m;
	// a[n]++;
	// return a;
}

void addmap(unordered_map<int, int> &a, map<int, int> &b){
	for(auto [c, d] : b){
		a[c]++;
		a[c]--;
		if (a[c] < d) a[c] = d;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	// ll a = 1;
	bool f = false;
	unordered_map<int, int> a;
	rep(i,0,n){
		ll t;
		cin >> t;
		if (D.count(t)) continue;
		D.insert(t);
		factor(a, t);
		// addmap(a, b);
		// a = lcm(a, t);
		// if (a >= k) f = true;
	}
	// auto b = factor(k);
	if (factor(a, k)){
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
}