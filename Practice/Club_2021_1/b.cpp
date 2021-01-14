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

int x[1007];
double y[1007];

int main() {
	int n, r;
	scanf("%d %d", &n, &r);
	rep(i, 0, n){
		scanf("%d", &x[i]);
		double my = r;
		rep(j,0,i){
			int dx = abs(x[i]-x[j]);
			if ( dx<=2*r ){
				my = max(my, y[j]+sqrt(4*r*r-dx*dx));
			}
		}
		y[i] = my;
	}
	rep(i,0,n){
		printf("%lf", y[i]);
		if (i<n-1) printf(" ");
		else printf("\n");
	}
}