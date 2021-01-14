#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// const int MAXN = 2e5+7;

int main() {
	int n, w;
	scanf("%d%d", &n, &w);
	vi a(n);
	vi b(n);
	vi c(n);
	rep(i,0,n){
		scanf("%d", &a[i]);
		w -= (a[i]+1)/2;
		b[i] = (a[i]+1)/2;
		c[i] = i;
	}
	sort(all(c), [&a](int A, int B){return a[A]>a[B];});
	if (w<0) {
		printf("-1\n");
	} else {
		for(int i=0; i<sz(a); ++i){
			int w2 = min(w, a[c[i]]-b[c[i]]);
			b[c[i]] += w2;
			w -= w2;
			if(!w) break;
		}
		rep(i,0,n){
			if (i!=0) printf(" ");
			printf("%d", b[i]);
		}
		printf("\n");
	}
}