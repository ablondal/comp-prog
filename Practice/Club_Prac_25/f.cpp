#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;

ll maxchild[MAXN];

vi adj[MAXN];
ll par[MAXN];
ll val[MAXN];
ll a[MAXN];

void DFS(int v, int onpath){
	if (val[v]==-1) {
		if (sz(adj[v])) {
			val[v] = 1e9+7;
			for(auto e:adj[v]){
				val[v] = min(val[v], val[e]);
			}
		}else{
			val[v] = onpath;
		}
	}
	a[v] = val[v] - onpath;
	for(auto e: adj[v]){
		DFS(e, val[v]);
	}
}

int main() {
	rep(i,0,MAXN) maxchild[i] = -1;
	int n;
	scanf("%d", &n);
	rep(i,2,n+1){
		int t;
		scanf("%d", &t);
		adj[t].push_back(i);
		par[i] = t;
	}

	rep(i,1,n+1){
		scanf("%lld", &val[i]);
		maxchild[par[i]] = max(maxchild[par[i]], val[i]);
	}

	DFS(1, 0);

	bool works = true;
	ll sum = 0;
	rep(i,1,n+1){
		if (a[i]>=0){
			sum+=a[i];
		}else{
			works = false;
			break;
		}
	}
	if (!works){
		printf("-1\n");
	}else{
		printf("%lld\n", sum);
	}
}












