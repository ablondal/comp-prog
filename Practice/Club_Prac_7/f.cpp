#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define max(a, b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define fori(i, n) for(int i=0; i<n; ++i)
typedef long long ll;

const int MAXN = 30007;
int P[MAXN] = {0};
int sz[MAXN] = {0};

int find(int v){
	if (P[v]==v) return v;
	return P[v] = find(P[v]);
}
int n, m, l;

int main(){
	scanf("%d", &n);
	fori(i,n){
		int a, b;
		scanf("%d%d", &a,&b);
		if (P[a]==0)P[a]=a;
		if (P[b]==0)P[b]=b;
		a = find(a);
		b = find(b);
		if (a==b) continue;
		if (sz[a]==0) sz[a]=1;
		if (sz[b]==0) sz[b]=1;
		if (sz[b]>sz[a]){
			swap(a,b);
		}
		sz[a]+=sz[b];
		P[b]=a;
	}
	int m=2*n, M=0;
	for(int i=1; i<=2*n; ++i){
		if(P[i]==i){
			M = max(M, sz[i]);
			m = min(m, sz[i]);
		}
	}
	printf("%d %d\n", m, M);
}















