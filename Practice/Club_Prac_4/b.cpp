#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 1000007
typedef long long ll;

bool V[MAX] = {0};
int nex[MAX] = {0};
int fin[MAX] = {0};
char name[MAX][12];

void DFSAssign(int A, int B){
	int C = A;
	do {
		fin[C] = B;
		V[C] = true;
		C = nex[C];
		B = nex[B];
	}while(C!=A);
}

int loopLen(int A){
	int C = nex[A];
	int len = 1;
	while(C!=A){
		C = nex[C];
		len++;
	}
	return len;
}

int goNSpaces(int A, int n){
	for(int i=0; i<n; ++i){
		A = nex[A];
	}
	return A;
}

int main(){
	ll n, m;
	scanf("%lli%lli", &n, &m);
	for(int i=1; i<=m; ++i){
		scanf("%s %i", name[i], &nex[i]);
	}
	for(int i=1; i<=m; ++i){
		if (V[i]) continue;
		ll loop = loopLen(i);
		DFSAssign(i, goNSpaces(i, n % loop));
	}
	for(int i=1; i<=m; ++i){
		printf("%s\n", name[fin[i]]);
	}
}
