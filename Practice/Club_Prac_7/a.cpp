#include <iostream>
#include <cstdio>
using namespace std;
#define max(a, b) ((a>b)?a:b)
const int N = 1e5+1;
int A[N], B[N], C[N];
int n;

int main(){
	int aa, bb, cc;
	scanf("%d", &n);
	A[0] = B[0] = C[0] = 0;
	for(int i=1; i<=n; ++i){
		scanf("%d%d%d", &aa, &bb, &cc);
		A[i] = aa + max(B[i-1], C[i-1]);
		B[i] = bb + max(A[i-1], C[i-1]);
		C[i] = cc + max(A[i-1], B[i-1]);
	}
	printf("%d\n", max(max(A[n], B[n]), C[n]));
}