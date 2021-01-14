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

typedef long double ld;

int DP[8] = {0, 3, 1, 3, 3, 3, 5, 5};

int main() {
	ll n;
	while(cin >> n){
		if(n==1){
			printf("3\n");
			continue;
		}
		int m = n % 4;
		ll tot = 0;
		if (m == 2){
			tot = n-1;
		}else if(m==1){
			tot = n-2;
		}else if(m==3){
			tot = n;
		}else{
			tot = n-1;
		}
		printf("%lld\n", tot);
	}

}