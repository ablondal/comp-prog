#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <queue>
#define min(a,b) ((a<b)?a:b)
const long long INF = 1e15;
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector <pll> G1[5001], G2[5001];

priority_queue <pll, vector<pll>, greater<pll> > Q;

ll d1[5001], d2[5001];

ll DP[5001][5001] = {{0}};
ll cost[5001][5001];

int n, b, s, r;

void dij(int s, ll d[], vector <pll> G[]){
	for(int i=1; i<=n; ++i){
		d[i] = INF;
	}
	Q.push({0, s});
	while(!Q.empty()){
		int v = Q.top().second;
		ll w = Q.top().first;
		Q.pop();
		if (w > d[v]) continue;
		for(auto edge : G[v]){
			ll chi = edge.first, len = edge.second;
			if (w+len < d[chi]) {
				d[chi] = w+len;
				Q.push({w+len, chi});
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d", &n,&b,&s,&r);
	int a,d,c;
	for(int i=0; i<r; ++i){
		scanf("%d%d%d",&a,&d,&c);
		G1[a].push_back({d,c});
		G2[d].push_back({a,c});
	}
	dij(b+1, d1, G1);
	dij(b+1, d2, G2);
	vector <ll> C(b);
	for(int i=0; i<b; ++i){
		C[i] = d1[i+1] + d2[i+1];
	}

	sort(C.begin(), C.end());

	// Get costs
	ll sum = 0;
	for(int i=0; i<b; ++i){
		sum = 0;
		for(int j=i; j<b; ++j){
			sum += C[j];
			cost[i+1][j+1] = sum * (j-i);
		}
	}

	// DP is min_cost[nums up to i][num of partitions]
	for(int i=1; i<=b; ++i){
		DP[i][1] = cost[1][i];

		for(int j=2; j<=i && j<=s; ++j){
			DP[i][j] = DP[i-1][j-1];
			for(int k=2; k <= i/j; ++k){
				DP[i][j] = min(DP[i][j], DP[i-k][j-1]+cost[i-k+1][i]);
			}
		}
	}

	printf("%lli\n", DP[b][s]);
}


















