#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	long long n, k;
	scanf("%lld%lld", &n, &k);
	vector<long long> opp;
	for(ll i=1; i*i<=n; ++i){
		if (n%i==0){
			k--;
			if (i*i!=n) opp.push_back(n/i);
		}
		if (k==0){
			printf("%lld\n", i);
			break;
		}
	}
	if (k==0) return 0;
	for(int i=sz(opp)-1; i>=0; --i){
		k--;
		if(k==0){
			printf("%lld\n", opp[i]);
			break;
		}
	}
	if (k){
		printf("-1\n");
	}
}