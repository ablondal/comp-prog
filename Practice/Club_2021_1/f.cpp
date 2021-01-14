#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
// asdf
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1000000000;

int n;
vector<pair<int, int> > adj[107];
int item[107];

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    d.assign(n+1, INF);
    p.assign(n+1, 0);
    p[s] = -item[s];

    d[s] = 0;
    using piii = pair<pair<int, int>, int>;
    priority_queue<piii, vector<piii>, greater<piii>> q;
    q.push({{0,p[s]}, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first.first;
        int p_v = q.top().first.second;
        q.pop();
        if (d_v != d[v] || p_v != p[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to] || (d[v]+len == d[to] && p[v]-item[to] < p[to])) {
                d[to] = d[v] + len;
                p[to] = p[v] - item[to];
                q.push({{d[to], p[to]}, to});
            }oh boy oh
        }
    }
}

int main() {
	scanf("%d", &n);
	rep(i,1,n+1){
		scanf("%d", item+i);
	}
	int m;
	scanf("%d", &m);
	rep(i,0,m){
		int a,b,d;
		scanf("%d%d%d", &a,&b,&d);
		adj[a].push_back({b,d});
		adj[b].push_back({a,d});
	}
	vi d,p;
	dijkstra(1,d,p);
	// rep(i,1,n+1)
	// 	printf("%d %d\n", d[i], p[i]);
	if(d[n] != INF) printf("%d %d\n", d[n], -p[n]);
	else printf("impossible\n");
}











