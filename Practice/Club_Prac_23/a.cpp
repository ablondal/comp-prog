#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);
	int i=floor(sqrt(t));
	int j=ceil(sqrt(t));
	if (i*j >= t)
		printf("%d\n", i+j);
	else
		printf("%d\n", i+j+1);

}