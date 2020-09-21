#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll DP[61] = {0};
ll DP2[61] = {0};

int main(){
	for(int i=1;i<61; ++i){
		DP[i] = 2*DP[i-1] + 1;
		// printf("%d %lli\n", i, DP[i]);
	}
	for(int i=1; i<61; ++i){
		DP2[i] = (DP[i])*((DP[i]+1)/2);
	}
	int t;
	scanf("%d", &t);
	while(t--){
		ll n;
		scanf("%lli", &n);
		int i=1;
		int tot = 0;
		while(n>0){
			n -= (DP[i])*((DP[i]+1)/2);
			if (n>=0) tot++;
			i++;
		}
		printf("%d\n", tot);
	}
}