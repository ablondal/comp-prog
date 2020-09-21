#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define max(a, b) ((a>b)?a:b)
#define fori(i, n) for(int i=0; i<n; ++i)
typedef long long ll;

const int MAXN = 1e5+3;
int P[MAXN] = {0};
ll L[MAXN] = {0};

int find(int v){
	return (v==P[v]?v:P[v]=find(v));
}
int n, m, l;

int main(){
	scanf("%d%d%d", &n, &m, &l);
	int n_comp = 0;
	for(int i=1; i<=n; ++i){
		scanf("%lli", &L[i]);
		if (L[i]>l){
			P[i] = i;
			n_comp++;
			if (L[i-1]>l){
				n_comp--;
			}
		}
	}
	for(int i=0; i<m; ++i){
		int r;
		scanf("%d", &r);
		if (r==0){
			printf("%d\n", n_comp);
		}else{
			int p, d;
			scanf("%d%d", &p, &d);
			if (l >= L[p] && l-L[p]<d){
				n_comp++;
				if (L[p-1]>l) n_comp--;
				if (L[p+1]>l) n_comp--;
			}
			L[p] += d;
			// for(int i=1; i<=n; ++i){
			// 	printf("%lli ", L[i]);
			// }
			// printf("\n");
		}
	}
}















