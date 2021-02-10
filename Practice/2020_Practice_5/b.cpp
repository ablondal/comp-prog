#include <bits/stdc++.h>
using namespace std;
// LOOK AT B2
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// const int primes[] = {2,3,5,7,11,13,17,19,23};
// const int sump[] = {2,3,5,7,11,13,17,19,23,29};

vi nums[101];
ll best[101] = {0};

int main() {
	best[1] = 1;
	best[2] = 2;
	best[3] = 3;
	nums[1].push_back(1);
	nums[2].push_back(2);
	nums[3].push_back(3);
	rep(i,4,101){
		rep(j,1,i){
			best[i] = max(best[i], lcm(best[j], best[i-j]));
		}
		if (best[i] < i) {
			best[i] = i;
			nums[i].push_back(i);
		}
		rep(j,1,i){
			if (best[i] == lcm(best[j], best[i-j])){
				nums[i].clear();
				rep(k,0,sz(nums[j])) nums[i].push_back(nums[j][k]);
				rep(k,0,sz(nums[i-j])) nums[i].push_back(nums[i-j][k]);
				break;
			}

		}
	}
	rep(n,1,101){
		printf("%lld", best[n]);
		rep(k,0,sz(nums[n])){
			printf(" %d", nums[n][k]);
		}
		printf("\n");
	}

	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);

		printf("%lld", best[n]);
		rep(k,0,sz(nums[n])){
			printf(" %d", nums[n][k]);
		}
		printf("\n");
	}
}