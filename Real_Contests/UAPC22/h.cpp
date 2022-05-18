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

ll binpow(ll a, ll n, ll M){
	ll r = 1;
	while(n > 0){
		if (n & 1){
			r = (r*a)%M;
		}
		a = (a*a)%M;
		n /= 2;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	if (n == 0){
		cout << 2 % m << endl;
		return 0;
	}
	ll b = binpow(2, n-1, m);
	b = b*5 - 1;
	b %= m;
	cout << b << endl;
}