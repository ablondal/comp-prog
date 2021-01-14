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
	int s, t, a, b, m, n;
	scanf("%d%d%d%d%d%d", &s, &t, &a, &b, &m, &n);
	int A, B=0;
	rep(i,0,m){
		scanf("%d", &A);
		if (a+A <= t && s <= a+A){
			B++;
		}
	}
	printf("%d\n", B);
	B = 0;
	rep(i,0,n){
		scanf("%d", &A);
		if (b+A <= t && s <= b+A){
			B++;
		}
	}
	printf("%d\n", B);
}