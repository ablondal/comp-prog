#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

vector<pair<int, ll>> adj[507];
// vector<pair<int, ll>> adj2[507];

ll D[507][507];
ll inf = 1LL << 60;

void dijkstra(int s, vector<ll> & d, int n) {
    // int n = adj.size();
    d.assign(n, inf);

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, t, d;
	cin >> n >> m >> t >> d;
	vi stations(t);
	rep(i,0,507) rep(j,0,507) D[i][j] = inf;
	rep(i,0,t) cin >> stations[i];
	stations.push_back(1);
	stations.push_back(n);
	rep(i,0,m){
		ll u, v, d;
		cin >> u >> v >> d;
		// adj[u].push_back({v, d});
		// adj[v].push_back({u, d});
		D[u][v] = min(D[u][v], d);
		D[v][u] = min(D[v][u], d);
	}
	rep(k,0,n+1) rep(i,0,n+1) rep(j,0,n+1) {
		D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	}
	rep(i,0,t+2) rep(j,i+1,t+2){
		int u = stations[i];
		int v = stations[j];
		// cout << u << "<->" << v << ": " << D[u][v] << endl;

		if (D[u][v] <= d) {
			adj[u].push_back({v, D[u][v]});
			adj[v].push_back({u, D[u][v]});
		}
	}
	vector<ll> dd(n+5);
	dijkstra(1, dd, n+5);
	if (dd[n] >= inf) {
		cout << "stuck" << endl;
	} else {
		cout << dd[n] << endl;
	}
}