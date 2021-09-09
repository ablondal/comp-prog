#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll INF = ((ll)1e12)+7;
vector<vector<pair<int, ll>>> adj;

vector<ll> tlog;

void dijkstra(int s, vector<ll> & d, vector<int> & p, vector<int> & num, vi& indices) {
    int n = adj.size();
    d.assign(n, INF);
    num.assign(n, 1);
    p.assign(n, -1);
    indices.assign(n, -1);
    // vector<bool> found(n, 0);

    d[s] = 0;
    using pli = pair<ll, int>;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({0, s});
    num[s] = 1;
    indices[s] = (tlog[0] == 0 ? 1 : 0);
    // cout << "d[2]=" << d[2] << endl;
    while (!q.empty()) {
        int v = q.top().second;
        int index = indices[v];
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        // found[v] = true;

        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;

            // printf("%lld->%lld: len:%lld ind:%lld\n", v, to, d[v] + len, index);

            // cout << tlog[index] << " " << d[v] + len << endl;
            if (index < tlog.size() && tlog[index] < d[v]+len) continue;
            // cout << "here" << d[to] << endl;
            if (d[v] + len == d[to]){
                num[to] = 2;
            } else if (d[v] + len < d[to]) {
                num[to] = num[v];
                d[to] = d[v] + len;
                p[to] = v;
                // cout << "ind" << index << endl;
                if (index == tlog.size() || tlog[index] > d[to]){
                    indices[to] = index;
                } else {
                    indices[to] = index+1;
                }
                // cout << "indto" << indices[to] << endl;
                q.push({d[to], to});
            }
        }
    }
}

// Two paths are considered distinct if there is a road used in one path that is not used in the other
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, d;
    cin >> n >> m >> d;
    adj.resize(n+5);
    // cout << "hi" << endl;
    rep(i,0,m){
        ll u,v,h;
        cin >> u >> v >> h;
        // cout << u << v << h << endl;
        adj[u].push_back({v,h});
    }
    tlog.resize(d);
    rep(i,0,d){
        cin >> tlog[i];
    }
    sort(all(tlog));
    vector<ll> dd;
    vector<int> pp, num, indices;
    dijkstra(1, dd, pp, num, indices);
    // cout << dd[n] << " " << indices[n] << endl;
    if (indices[n] == tlog.size()) {
        if (num[n] == 2) {
            cout << 1 << endl;
        } else {
            vector<int> path;
            int par = n;
            while(par != -1) {
                path.push_back(par);
                par = pp[par];
            }
            cout << path.size() << endl;
            for(int i=path.size()-1; i>=0; --i){
                cout << path[i] << endl;
            }
        }
    } else {
        cout << 0 << endl;
    }
}