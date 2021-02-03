#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int v1, v2;
int t, d;

int main() {
	scanf("%d%d%d%d", &v1, &v2, &t, &d);
	if (v1 < v2) swap(v1, v2);
	int ans = 0;
	rep(i,0,t){
		ans += v2;
		// printf("%d\n", v2);
		v2 = min(v2+d, v1+(d*(t-i-2) ));
	}
	printf("%d\n", ans);
}