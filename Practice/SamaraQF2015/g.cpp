#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
// typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vector<pair<int, ll>> adj[100007];
int cts[100007];

const ll INF = 1e18;

void dijkstra(int n, vector<pair<ll, int>> &d) {
    // int n = adj.size();
    d.assign(100007, {INF,0});

    using pii = pair<ll, pair<int, int>>;
    priority_queue<pii, vector<pii>, greater<pii>> q;

    for(int i=1; i<n+1; ++i){
        if (cts[i]){
            d[i] = {0, i};
            q.push({0, {i, i}});
        }
    }

    while (!q.empty()) {
        ll v = q.top().second.first;
        ll ss = q.top().second.second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v].first)
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v].first + len < d[to].first) {
                d[to].first = d[v].first + len;
                d[to].second = ss;
                q.push({d[to].first, {to, ss}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    rep(i,1,n+1){
        // int a;
        cin >> cts[i];
        // if (a) cts[i] = 1;
    }
    vector<pair<int, pair<int, int>>> edges;
    rep(i,0,m){
        ll w;
        int u,v;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({w, {u,v}});
    }

    ll mm = 1e18;
    int a,b;

    vector<pair<ll, int>> d;
    dijkstra(n, d);

    for(auto& [w, uv] : edges){
        auto& [u,v] = uv;
        if (d[u].second != d[v].second){
            ll tmp = d[u].first + d[v].first + w;
            if (tmp < mm){
                mm = tmp;
                a = d[u].second;
                b = d[v].second;
            }
        }
    }

    if (mm == 1e18){
        cout << "No luck at all" << endl;
        return 0;
    }

    cout << mm << endl;
    cout << a << ' ' << b << endl;

}