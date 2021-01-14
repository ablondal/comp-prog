#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char vis1[10007];
char vis[10007];
int M[10007];
int M2[10007];
vector<pair<int, int> > adj[10007];
int N, MM;
int currM;

int DFS(int v){
	if(vis1[v]) return false;
	vis1[v] = true;
	for(auto e : adj[v]){
		if (e.second<=currM && !vis[e.first]){
			vis[e.first]=true;
			if(!M[e.first] || DFS(M[e.first])){
				M[e.first]=v;
				M2[v] = true;
				return true;
			}
		}
	}
	return false;
}

int flowonce(){
	// printf("FLowing once, %d\n", currM);
	memset(vis,false,10007);
	memset(vis1,false,10007);
	int tot = 0;
	rep(i,1,N+1){
		if (M2[i]) continue;
		tot += DFS(i);
	}
	return tot;
}

int main() {
	scanf("%d%d", &N, &MM);
	rep(i,0,MM){
		int u,v,d;
		scanf("%d%d%d", &u, &v, &d);
		adj[u].push_back({v,d});
	}
	int lo=0, hi=1e9+7;
	while(lo<hi){
		int mid = (lo+hi)/2;
		currM = mid;
		rep(i,0,10007) M2[i] = M[i]=0;
		int res = 1;
		int tot = 0;
		while(res){
			res = flowonce();
			tot += res;
			// printf("%d\n", tot);
		}
		if (tot==N){
			hi = mid;
		}else{
			lo = mid+1;
		}
	}
	if (hi == 1e9+7) printf("-1\n");
	else{
		printf("%d\n", hi);
	}
}










