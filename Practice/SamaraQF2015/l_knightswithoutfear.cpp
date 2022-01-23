#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef __int128 ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll mygcd(ll a, ll b){
	if (a==0) return b;
	return mygcd(b%a, a);
}

ll binpow(ll a, ll b, ll m){
	ll res = 1;
	while(b){
		if (b&1) res *= a;
		a = (a*a)%m;
		b >>= 1;
	}
	return res;
}

// Assert m1 and m2 are coprime
ll crt(ll m1, ll r1, ll m2, ll r2){
	ll m = m1*m2;
	ll M1 = binpow(m1, m2-2, m2);
	ll M2 = binpow(m2, m1-2, m1);
	ll x1 = (((r1 * M2)%m) * m2)%m;
	ll x2 = (((r2 * M1)%m) * m1)%m;
	return (x1+x2)%m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	long long nn, mm;
	cin >> nn >> mm;
	n = nn;
	m = mm;
	if (n==1 && m==1) cout << 1 << endl;
	else if (n==1 || m==1) cout << 2 << endl;
	else if (mygcd(n,m)==1) {
		mm = min(n*m, min(crt(n,1,m,0), crt(n,0,m,1)));
		cout << mm << endl;
	} else {
		mm = (n*m)/mygcd(n,m);
		cout << mm << endl;
	}

	
}