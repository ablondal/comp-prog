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
	int p,d;
	scanf("%d%d", &p, &d);
	long double n = 1.0;
	rep(i,1,p){
		n *= (((double)d-i)/(d));
	}
	printf("%Lf\n", 1-n);
}