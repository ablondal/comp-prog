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
const ll MOD = 1e9+7;
typedef vector<vll> mat;

mat mat_mul(mat& a, mat& b){
	int n = sz(a);
	mat c(n, vll(n, 0));
	rep(i,0,n){
		rep(j,0,n){
			rep(k,0,n){
				c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % MOD;
			}
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll k;
	cin >> n >> k;
	mat adj(n, vll(n, 0));
	rep(i,0,n){
		rep(j,0,n){
			cin >> adj[i][j];
		}
	}
	mat res(n, vll(n, 0));
	rep(i,0,n) res[i][i] = 1;
	while(k){
		if (k & 1) {
			res = mat_mul(res, adj);
		}
		adj = mat_mul(adj, adj);
		k >>= 1;
	}
	ll tot = 0;
	rep(i,0,n) rep(j,0,n) tot = (tot + res[i][j]) % MOD;
	cout << tot << endl;
}