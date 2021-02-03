#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// const long double pi = 3.141592653589793;

int main() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	if (k >= n/2) {
		printf("%lld\n", (n)*(n-1)/2);
	} else {
		ll ans = 0;
		rep(i,0,2*k){
			ans += (n-1)-i;
		}
		printf("%lld\n", ans);
	}
}