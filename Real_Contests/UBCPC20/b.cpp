#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi a;




int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	a.resize(n);
	int totsum=0;	
	rep(i,0,n){
		cin >> a[i];
		totsum += a[i];
	}
	int lo = 1;
	int hi = totsum+1;

	while(hi!=lo){
		int mid = (hi+lo)/2;
		int tmps = 0;
		int kk = 0;
		rep(i,0,n){
			if(a[i]>mid){
				kk=k+1;
				break;
			}
			if (tmps==0){
				tmps+=a[i];
			}else if(tmps+a[i]>mid){
				kk++;
				tmps=a[i];
			}else{
				tmps+=a[i];
			}			
		}
		if(kk<k) hi=mid;
		else lo=mid+1;
		// printf("%d %d\n", lo, hi);
	}
	printf("%d\n",lo);
	
}
























