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

char S[10007];
char S2[10007];

int main() {
	scanf(" %s", S);
	rep(i,0,10007) S2[i] = S[i];
	int m;
	scanf("%d", &m);
	rep(i,0,m){
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		if (r == l) continue;
		l--;
		k %= (r - l);
		rep(j, 0, r-l){
			S2[l + j] = S[ l + (j + r-l - k) % (r-l) ];
			// printf("%s\n", S2);
		}
		rep(j, 0, r-l){
			S[l+j] = S2[l+j];
		}
	}
	printf("%s\n", S);
}