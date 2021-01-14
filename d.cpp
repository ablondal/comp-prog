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

int main() {
	int n, k, p;

	scanf("%d%d%d", &n, &k, &p);

	ll choose[50][50];
	rep(i,1,50) choose[i][0] = choose[i][i] = 1;
	rep(i,2,50) rep(j,1,i){
		choose[i][j] = (choose[i-1][j-1]+choose[i-1][j])%p;
	}

	if (n >= k*k+1){
		printf("0\n");
		return 0;
	}
	if (n == k*k){
		printf("4\n");
		return 0;
	}
	ll num = 4 * choose[n][k*k-n];
	num %= p;
	printf("%lli\n", num);

}