#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int DP[3007][3007] = {{0}};
int P[3007][3007] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi t(n+1);
	rep(i,1,n+1) cin >> t[i];
	int m;
	cin >> m;
	vector<vector<pair<int, int>>> adj(n+1);
	rep(i,0,m){
		int a,b,d;
		cin >> a >> b >> d;
		adj[a].push_back({b,d});
		adj[b].push_back({a,d});
	}

	vi d(n+1,1e8);
	vi num(n+1,0);

	priority_queue<pii, vector<pii>, greater<pii>> Q;
	d[1] = 0;
	num[1] = t[1];
	Q.push({0,1});
	while(!Q.empty()){
		auto d_to = Q.top().first;
		auto v_to = Q.top().second;
		Q.pop();
		if (d_to != d[v_to]) continue;
		for(auto [to, dd] : adj[v_to]){
			if (d_to + dd < d[to]){
				num[to] = num[v_to] + t[to];
				d[to] = d_to + dd;
				Q.push({d[to], to});
			} else if (d_to + dd == d[to]){
				num[to] = max(num[to], num[v_to] + t[to]);
			}
		}
	}

	if (d[n] == 1e8){
		cout << "impossible" << endl;
	} else {
		cout << d[n] << " " << num[n] << endl;
	}

}