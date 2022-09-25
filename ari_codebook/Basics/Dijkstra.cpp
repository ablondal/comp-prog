/* Taken from cp-algorithms.com */
/* O(m log m) */
const int INF = 1e9;
vi adj[MAXN];

void dij(int s, int n, vi &d, vi &p){
	d.assign(n, INF);
	p.assign(n, -1);

	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}