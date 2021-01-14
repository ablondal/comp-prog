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
	int n, s;
	scanf("%d%d", &n, &s);
	if ( s-n+1 > n ) {
		printf("YES\n");
		rep(i,0,n){
			int num = (i==n/2) ? s-n+1 : 1;
			if (i) {
				printf(" %d", num);
			}else{
				printf("%d", num);
			}
		}
		printf("\n%d\n", n);
	} else {
		printf("NO\n");
	}
}