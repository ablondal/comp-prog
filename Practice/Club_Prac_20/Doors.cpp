#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	int b =0;
	int t;
	rep(i,0,n){
		scanf("%d", &t);
		if (t<=x){
			b++;
		}
	}
	if(x>y){
		printf("%d\n", n);
	}else if(y>=x){
		printf("%d\n", (b+1)/2);
	}
}










