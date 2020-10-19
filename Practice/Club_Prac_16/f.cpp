#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a, b, c, d, v, w, x, y, z;
int n;

int main() {
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

	ll tot = 0;

	rep(i, 1, n+1){
		x = i;
		z = x + a - d;
		w = x + b - c;
		v = a + w - d;
		if (z < 1 || z > n || w < 1 || w > n || v < 1 || v > n){
			continue;
		}else if (v != b + z - c){
			continue;
		}else{
			tot++;
		}
	}

	tot *= n;
	printf("%lli\n", tot);
}























