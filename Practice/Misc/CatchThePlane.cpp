#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
typedef long long ll;
const int MAXN = 1e6+7;

struct bus{
	int to;
	ll s, t;
	long double p;
};

bus B[MAXN];
vector <int> adj[MAXN];
vector <long double> DP[MAXN];
int ptr[MAXN] = {0};
int n, m, from;
ll k;

inline bool myLess(int a, int b){
	return (B[a].s > B[b].s);
}

long double DFS(int b){
	int v;
	ll t;
	if (b == -1){
		v = 0;
		t = -1;
	}else{
		v = B[b].to;
		t = B[b].t;
	}

	if (t > k) return 0;
	if (v == 1) return 1;
	if (!adj[v].size() || B[adj[v][0]].s <= t) return 0;

	if (ptr[v] == adj[v].size() || B[adj[v][ptr[v]]].s <= t){
		// do bin search
		int lo=0, hi=adj[v].size();
		while(lo!=hi-1){
			int mid = (lo+hi) / 2;
			if (B[adj[v][mid]].s <= t) hi = mid;
			else lo = mid;
		}
		// printf("Returning from DP[%d][%d]: %Lf\n", v, lo, DP[v][lo]);
		return DP[v][lo];
	}
	long double nextB = 0;
	if (ptr[v]) nextB = DP[v][ptr[v]-1];
	long double best = 0;
	if (ptr[v]) best = DP[v][ptr[v]-1];
	while(ptr[v] < adj[v].size() && B[adj[v][ptr[v]]].s > t){

		DP[v][ptr[v]] = DFS( adj[v][ptr[v]] );
		DP[v][ptr[v]] = B[adj[v][ptr[v]]].p * DP[v][ptr[v]] + (1-B[adj[v][ptr[v]]].p) * nextB;
		if (DP[v][ptr[v]] < best){
			DP[v][ptr[v]] = best;
		}
		// printf("%d: %Lf\n", adj[v][ptr[v]], DP[v][ptr[v]]);
		best = DP[v][ptr[v]];
		ptr[v]++;
		if (ptr[v] < adj[v].size() && B[adj[v][ptr[v]-1]].s > B[adj[v][ptr[v]]].s){
			nextB = DP[v][ptr[v]-1];
		}
	}
	// printf("%d: %Lf\n", b, DP[v][ptr[v]-1]);
	return DP[v][ptr[v]-1];
}

int main(){
	scanf("%d%d%lli", &m, &n, &k);
	for(int i=0; i<m; ++i){
		scanf("%d%d%lli%lli%Lf", &from, &B[i].to, &B[i].s, &B[i].t, &B[i].p);
		adj[from].push_back(i);
		DP[from].push_back(-1);
	}
	for(int i=0; i<n; ++i){
		sort(adj[i].begin(), adj[i].end(), myLess);
	}
	printf("%0.8Lf\n", DFS(-1));
}
















