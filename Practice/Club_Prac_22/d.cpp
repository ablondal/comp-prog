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
	int n, m;
	scanf("%d%d", &n, &m);
	vi a(n);
	vi b(m);
	rep(i,0,n){
		scanf("%d",&a[i]);
	}
	rep(i,0,m){
		scanf("%d",&b[i]);
	}
	sort(all(a));
	for(auto &c : b){
		int lo=0, hi=n+1;
		while(hi-lo>1){
			int mid = (lo+hi)/2;
			if(a[mid-1]<=c){
				lo=mid;
			}else{
				hi=mid;
			}
		}
		c = lo;
	}
	rep(i,0,m){
		if(i!=0) printf(" ");
		printf("%d",b[i]);
	}
	printf("\n");

}