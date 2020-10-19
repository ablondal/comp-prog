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

int minc[107] = {0};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	rep(i,0,n){
		minc[i] = (int) 1e9+2;
		rep(j,0,m){
			int a;
			scanf("%d", &a);
			minc[i] = min(minc[i], a);
		}
	}
	int ma = 0;
	rep(j, 0, n){
		ma = max(ma, minc[j]);
	}
	printf("%d\n", ma);
}