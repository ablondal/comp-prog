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
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef long double ld;

int main() {
	int n;
	cin >> n;
	while(n--){
		ld A, B, C;
		cin >> A >> B >> C;
		if (B>A){
			swap(A,B);
		}
		if (C>A){
			swap(A,C);
		}
		ld x = (B*B - C*C)/(2*A);
		ld y = sqrtl(B*B - (x + (A/2))*(x + (A/2)) );

		// printf("%Lf %Lf\n", x,y);

		ld lo=0, hi=1e6;
		while(hi-lo>1e-14){
			ld m = lo/2 + hi/2;
			if ( (A/2)*(A/2) + m*m > x*x + (y-m)*(y-m)){
				hi = m;
			}else{
				lo = m;
			}
			// printf("%Lf %Lf\n", lo, hi);
		}
		// printf("%Lf\n", lo);
		ld h = sqrtl((A/2)*(A/2) + lo*lo);

		ld price = (h*h + h + 1);
		printf("%0.3Lf\n", price);
	}
}