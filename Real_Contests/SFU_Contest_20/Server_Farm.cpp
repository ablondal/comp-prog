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
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[107][107] = {{0}}; // #odd, #even

int main() {
	int n;
	cin >> n;
	while(n>0){
		double N = sqrt(n);
		double a = floor(N);
		double b = ceil(N);
		if (n < 5){
			printf("0\n");
		}
		else if (n/a + a <= n/b + b){
			printf("%d\n", (int)a);
		}else{
			printf("%d\n", (int)b);
		}
		cin >> n;
	}
}