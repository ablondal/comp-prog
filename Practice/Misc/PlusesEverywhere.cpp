#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

char digs[100007];
ll tenexp[100007];
ll ch_k[100007];
ll ch_k1[100007];

ll f_exp(ll n, ll c){
	ll tot = 1;
	while( c > 0 ){
		if (c & 1){
			tot *= n;
			tot %= MOD;
		}
		c = c >> 1;
		n *= n;
		n %= MOD;
	}
	return tot;
}

ll divi(ll a, ll b){
	return (a * f_exp(b, MOD-2)) % MOD;
}

ll choose(ll n, ll k){
	ll tot = 1;
	for(int i=k+1; i<=n; ++i){
		tot *= i;
		tot %= MOD;
	}
	ll di = 1;
	for(int i=2; i<=(n-k); ++i){
		di *= i;
		di %= MOD;
	}
	printf("%lli / %lli\n", tot, di);
	return divi(tot, di);
}

int main(){
	ll n, k;
	scanf("%lli%lli", &n, &k);
	scanf(" %s", digs);
	if (k==0) {
		ll tot = 0;
		for(int i=0; i<n; ++i){
			tot = (10 * tot) % MOD;
			tot += digs[i] - '0';
		}
		printf("%lli\n", tot);
		return 0;
	}

	tenexp[0] = 1;
	for(int i=1; i<=n-k; ++i){
		tenexp[i] = (tenexp[i-1] * 10) % MOD;
	}

	ch_k[k] = 1;
	for(int i=k+1; i<n; ++i){
		ch_k[i] = (ch_k[i-1] * divi(i, i-k)) % MOD;
	}

	ch_k1[k-1] = 1;
	for(int i=k; i<n-1; ++i){
		ch_k1[i] = (ch_k1[i-1] * divi(i, i-k+1)) % MOD;
	}

	ll tot = 0;
	ll currC = 0;
	ll d;
	for(int i=0; i<n; ++i){
		d = digs[n-i-1] - '0';
		// printf("%lli\n", currC);
		tot += currC * d;
		tot %= MOD;
		if (n - i - 1 >= k){
			tot += (tenexp[i] * d * ch_k[n-i-1]) % MOD;
			tot %= MOD;
			currC += (tenexp[i] * ch_k1[n-i-2]) % MOD;
			currC %= MOD;
		}
	}
	printf("%lli\n", tot);
}









