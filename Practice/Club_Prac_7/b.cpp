#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define max(a, b) ((a>b)?a:b)
typedef long long ll;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> H(n);
	ll tot = 0;
	for(int i=0; i<n; ++i){
		scanf("%d", &H[i]);
		tot += H[i];
	}
	sort(H.begin(), H.end());
	for(int i=n-1; i>=n-k && i>=0; --i){
		tot -= H[i];
	}
	printf("%lli\n", tot);
}