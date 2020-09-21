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
const int MAXN = 1007;

// We do Max-independant, and then the converse of that is the answer :D

vi G[MAXN];
vi Y, N;

void DFS(int V, int P){
	Y[V] = 1;
	N[V] = 0;
	if (G[V].size() == 1 && G[V][0] == P){
		return;
	}
	for( auto c : G[V] ){
		if (c == P) continue;
		DFS(c, V);
		Y[V] += N[c];
		N[V] += max(N[c], Y[c]);
	}
}

int main(){
	int n, tmp, ni;
	while(true){
		scanf("%d", &n);
		if (!n) break;
		Y.clear();
		N.clear();
		Y.resize(n+1, -1);
		N.resize(n+1, -1);
		for(int i=1; i<=n; ++i){
			G[i].clear();
			scanf("%d", &ni);
			for(int j=0; j<ni; ++j){
				scanf("%d", &tmp);
				G[i].push_back(tmp);
			}
		}
		DFS(1, 0);
		if (n == 1) printf("1\n");
		else printf("%d\n", n - max(Y[1], N[1]));
	}
}