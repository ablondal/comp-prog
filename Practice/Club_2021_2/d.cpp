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

int b[507][507];
int n, m, q;
int c[507] = {0};

int main() {
	scanf("%d%d%d", &n, &m, &q);
	int curr = 0;
	rep(i,0,n){
		curr = 0;
		rep(j,0,m){
			scanf("%d", &b[i][j]);
			if (b[i][j]) curr++;
			else curr = 0;
			c[i] = max(c[i], curr);
		}
	}
	rep(k,0,q){
		int e,f;
		scanf("%d%d", &e, &f);
		b[e-1][f-1] = !b[e-1][f-1];
		c[e-1] = 0;
		curr = 0;
		rep(j,0,m){
			if (b[e-1][j]) curr++;
			else curr = 0;
			c[e-1] = max(c[e-1], curr);
		}
		int M = 0;
		rep(i,0,n){
			M = max(M, c[i]);
		}
		printf("%d\n", M);
	}
}