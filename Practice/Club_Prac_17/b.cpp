#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		ll n;
		scanf("%lli", &n);
		ll ans = n * (n+1);
		ans /= 2;
		ll k=1;
		while(n){
			k *= 2;
			n = n / 2;
		}
		// printf("%lli\n", k);
		ans -= 2 * k;
		ans += 2;
		printf("%lli\n", ans);

	}
}