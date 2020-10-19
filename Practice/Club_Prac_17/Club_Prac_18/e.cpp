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

ll DP[100007] = {0};

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k;
		scanf("%d%d", &n, &k);
		DP[n+1] = DP[k] = 0;
		DP[n] = 1;
		for(int i=n-1; i>=max(k, 1); --i){
			DP[i] = DP[i+1]+DP[i+2];
			DP[i] %= (ll)1e9+7;
		}
		if (n!=0)
			DP[0] = DP[2];
		printf("%lli\n", DP[k]);
	}
}