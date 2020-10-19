#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int n, d, r;
	scanf("%d%d%d", &n, &d, &r);
	while(n || d || r){
		// priority_queue <int> Q;
		// rep(i,0,n){
		// 	int x;
		// 	scanf("%d", &x);
		// 	Q.push(x);
		// }
		vi N(n), D(n);
		rep(i,0,n) scanf("%d", &D[i]);
		rep(i,0,n) scanf("%d", &N[i]);
		sort(all(D));
		sort(all(N));
		int tot = 0;
		rep(i,0,n){
			if (D[i] + N[n-i-1] > d){
				tot += D[i] + N[n-i-1] - d;
			}
		}
		printf("%d\n", tot*r);
		scanf("%d%d%d", &n, &d, &r);
	}
}