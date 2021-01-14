#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 3e5+7;

vi adj[MAXN];
int V[MAXN] = {0};

int x, y, n;

int DFS(int p, int v) {
	V[v]=1;
	bool yy = (v==y) ? 1 : 0;
	for(auto e : adj[v]){
		if (e!=p){
			yy |= DFS(v, e);
			V[v] += V[e];
		}
	}
	return yy;
}

int main() {
	scanf("%d%d%d", &n, &x, &y);
	rep(i,0,n-1){
		int a,b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int tot = 0;
	for(auto e : adj[x]){
		int yy = DFS(x, e);
		if (!yy){
			tot += V[e];
		}
	}
	ll num = tot+1;
	num *= V[y];
	// printf("%lld\n", num);
	num = ((ll)n*(n-1)) - num;
	printf("%lld\n", num);
}