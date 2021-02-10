#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 5e4+7;

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

ll best[107] = {0};

vi comb[107];

vi curr;

void DFS(int i, ll mult, ll sum){
	if (mult > best[sum]){
		best[sum] = mult;
		comb[sum].clear();
		for(int j=0; j<sz(curr); ++j){
			comb[sum].push_back(curr[j]);
		}
	}
	if (primes[i]==101) return;
	DFS(i+1, mult, sum);
	int n_m = primes[i];
	while(n_m+sum <= 100){
		curr.push_back(n_m);
		DFS(i+1, mult*n_m, sum+n_m);
		curr.pop_back();
		n_m *= primes[i];
	}
}

int main() {
	rep(i,0,101){
		DFS(0,1,i);
		curr.push_back(1);
	}
	// DFS(0,1,0);
	// rep(i,1,101){
	// 	printf("%lld\n", best[i]);
	// 	for(auto b: comb[i]){
	// 		printf(" %d", b);
	// 	}
	// 	printf("\n");
	// }
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		printf("%d", best[n]);
		int sum = 0;
		sort(comb[n].begin(), comb[n].end());
		for(int j = 0; j<sz(comb[n]); ++j){
			int b = comb[n][j];
			rep(i,0,b-1){
				printf(" %d", sum+i+2);
			}
			printf(" %d", sum+1);
			sum += b;
		}
		printf("\n");
	}
}