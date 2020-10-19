#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ll sz, p;
	scanf("%lli%lli", &sz, &p);
	while(sz || p){
		int n = floor(sqrt(p));
		int x=0, y=0;
		if (n%2==0) n--;
		if (p==n*n){
			y = x = (sz+n)/2;
		}else{
			int r = p - n*n;
			int e = r / (n+1);
			if (e==0){
				x=(sz+n)/2 - r%(n+1) + 1;
				y=(sz+n)/2 + 1;
			}else if (e==1){
				x=(sz-n)/2;
				y=(sz+n)/2 + 1 - r%(n+1);
			}else if (e==2){
				x=(sz-n)/2 + r%(n+1);
				y=(sz-n)/2;
			}else{
				x=(sz+n)/2 + 1;
				y=(sz-n)/2 + r%(n+1);
			}
		}
		
		printf("Line = %d, column = %d.\n", y, x);
		scanf("%lli%lli", &sz, &p);
	}
}























