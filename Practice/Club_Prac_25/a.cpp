#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
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
		int d;
		scanf("%d", &d);
		if (d==36) {
			printf("YES\n5 6 10 15\n");
		}else if (d==40) {
			printf("YES\n6 14 15 5\n");
		}else if (d==44) {
			printf("YES\n6 7 10 21\n");
		}else if (d>30) {
			printf("YES\n%d %d %d %d\n", 6, 10, 14, d-30);
		} else {
			printf("NO\n");
		}
	}
}