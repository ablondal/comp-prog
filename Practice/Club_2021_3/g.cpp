#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <numeric>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// const long double pi = 3.141592653589793;
// const int MAXN = 1e5+7;

int x[1007], y[1007];

int main() {
	int n, x1, y1;
	scanf("%d%d%d", &n, &x1, &y1);
	int num = n;
	rep(i,0,n){
		scanf("%d%d", x+i, y+i);
		x[i]-=x1;
		y[i]-=y1;
		if (y[i]<0){
			x[i]*=-1;
			y[i]*=-1;
		}
		if (y[i]==0) x[i] = abs(x[i]);
		int g = gcd(abs(x[i]), y[i]);
		x[i]/=g;
		y[i]/=g;
		rep(j,0,i){
			if (x[j]==x[i] && y[j]==y[i]){
				num--;
				break;
			}
		}
	}
	printf("%d\n", num);

}