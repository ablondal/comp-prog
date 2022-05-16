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
typedef vector<vll> mat;
const ll MOD = 1e7;

mat matmul(mat a, mat b){
	mat c(2,vll(2));
	rep(i,0,2)rep(j,0,2){
		c[i][j] = 0;
		rep(k,0,2){
			c[i][j] += a[i][k]*b[k][j];
			c[i][j] %= MOD;
		}
	}
	return c;
}

mat operator+(mat a, mat b){
	mat c(2,vll(2));
	rep(i,0,2)rep(j,0,2){
		c[i][j] = a[i][j]+b[i][j];
		c[i][j] %= MOD;
	}
	return c;
}

mat matpow(mat a, ll n){
	mat r(2,vll(2,0));
	r[0][0] = r[1][1] = 1;
	while(n>0){
		if (n & 1){
			r = matmul(r,a);
		}
		a = matmul(a, a);
		n /= 2;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k, l;
	cin >> n >> k >> l;
	n /= 5;
	k %= MOD;
	l %= MOD;
	mat a = {{k, l},{1,0}};
	mat r = matpow(a, n);
	string s;
	int e = r[0][0];
	rep(i,0,6){
		s.push_back('0'+(e%10));
		e /= 10;
	}
	reverse(all(s));
	cout << s << endl;
}