#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 500;
const ll M = 1e9+7;

ll choose[MAXN+1][MAXN+1] = {{0}};
ll fac[MAXN+1] = {0};
ll inv_fac[MAXN+1] = {0};

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll inv(ll b, ll m){
	return binpow(b, m-2, m);
}

ll binom(ll n, ll x, ll m){
	return ((fac[n] * inv_fac[x]) % m) * inv_fac[n-x] % m;
}

int main() {
	// Populate choose
	for(int i=0; i<=MAXN; ++i){
		choose[i][0] = choose[i][i] = 1;
		for(int j=1; j<i; ++j){
			choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
			choose[i][j] %= M;
		}
	}

	// Populate fac
	fac[0] = 1;
	for(int i=1; i<=MAXN; ++i){
		fac[i] = (i * fac[i-1]) % M;
	}

	// Populate inv_fac
	inv_fac[MAXN] = inv(fac[MAXN], M);
	for(int i=MAXN; i>0; --i){
		inv_fac[i-1] = (inv_fac[i] * i) % M;
	}

	// printf("%lli %lli %lli %lli\n", fac[1], inv_fac[1], fac[4]*inv_fac[4] % M, inv_fac[0]);

	printf("%lli %lli\n", choose[230][64], binom(230, 64, M));

	int t;
	scanf("%d", &t);
	while(t--){
		;
	}
}













