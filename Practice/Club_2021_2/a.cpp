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

int a[1000], b[1000];

int main() {
	int n;
	int t = 0;
	scanf("%d", &n);
	rep(i,0,n) scanf("%1d", a+i);
	rep(i,0,n) scanf("%1d", b+i);
	rep(i,0,n) t += min(abs(a[i]-b[i]), min(a[i]-b[i]+10, abs(a[i]-b[i]-10)));
	printf("%d\n", t);
}