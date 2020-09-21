#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
// const int MAXN = 1000;

// vi G[MAXN];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n, m, totc = 0;
		int tmp;
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; ++i){
			scanf("%d", &tmp);
			totc += tmp;
		}
		if (m < n || n == 2){
			printf("-1\n");
		}else{
			printf("%d\n", totc*2);
			for(int i=1; i<=n; ++i){
				printf("%d %d\n", i, (i%n)+1);
			}
		}
	}
	
}