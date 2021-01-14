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
	int n;
	scanf("%d", &n);
	vi a(n);
	int tot = 0;
	rep(i,0,n){
		scanf("%d",&a[i]);
		tot += a[i];
	}
	int big = tot % n;
	int sz = tot / n;
	int sm = n - big;
	int newtot = 0;
	rep(i,0,n){
		if(a[i]>sz){
			if(big){
				big--;
				newtot += a[i]-sz-1;
			}else{
				sm--;
				newtot += a[i]-sz;
			}
		}else{
			if(sm){
				sm--;
				newtot += sz-a[i];
			}else{
				big--;
				newtot += sz-a[i]+1;
			}
		}
	}
	printf("%d\n", newtot/2);
}