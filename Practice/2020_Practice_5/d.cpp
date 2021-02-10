#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 5e4+7;

// const int primes[] = {2,3,5,7,11,13,17,19,23};
// const int sump[] = {2,3,5,7,11,13,17,19,23,29};

vector<pair<int, ll>> adj[MX];
ll kids[MX] = {0};
ll N;
ll tot = 0;

ll DFS(int v, int p){
	kids[v] = 1;
	for(auto [e, c] : adj[v]){
		if (e==p) continue;
		kids[v] += DFS(e, v);
		tot += ((ll)kids[e]*(N-kids[e]))*c;
	}
	return kids[v];
}

int main() {
	scanf("%lld", &N);
	rep(i,0,N-1){
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	DFS(1, -1);
	// rep(i,1,N+1){
	// 	printf("%d %d\n", i, kids[i]);
	// }
	printf("%0.8Lf\n", 2 * tot / (long double)(N*(N-1)));
}