#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define max(a, b) ((a>b)?a:b)
#define fori(i, n) for(int i=0; i<n; ++i)
typedef long long ll;

ll H;

int main(){
	scanf("%lli", &H);
	ll n_a = 0;
	ll m = 1;
	while(H>1){
		n_a	+= m;
		H /= 2;
		m *= 2;
	}
	n_a += m;
	printf("%lli\n", n_a);
}















