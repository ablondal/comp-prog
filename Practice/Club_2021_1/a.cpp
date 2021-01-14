#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ll m, n;
	scanf("%lld%lld", &m, &n);
	ll k = gcd(m,n);
	if (m/k % 2 == 0 || n/k % 2 ==0) printf("0\n");
	else printf("%lld\n", gcd(m,n));
}