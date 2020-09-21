#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int MAX = 25007;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vpii G1[MAX];
vi G2[MAX];

priority_queue <pii, vpii, greater<pii> > Q;
int d[MAX];

int n, m, c;

char vis[MAX];
short res[MAX][MAX] = {{0}};

void makeDijTree(){
	for(int i=0; i<=n; ++i){
		d[i] = INF;
	}
	Q.push({0, 1});
	d[1] = 0;
	while(!Q.empty()){
		int v = Q.top().second;
		int w = Q.top().first;
		Q.pop();
		if (d[v] < w) continue;
		for(pii c : G1[v]){
			if (w + c.second < d[c.first]){
				G2[c.first].clear();
				d[c.first] = w + c.second;
				Q.push({w+c.second, c.first});
			}
			if (w + c.second == d[c.first]){
				G2[c.first].push_back(v);
			}
		}
	}
}

bool dfs(int v, int t){
	if (v==t) return true;
	vis[v] = true;
	for(auto nxt: G1[v]){
		int to = nxt.first;
		if (!vis[to] && res[v][to]){
			if (dfs(to, t)){
				res[v][to]--;
				res[to][v]++;
				return true;
			}
		}
	}
	return false;
}

int maxflow(int s, int t){
	for(int i=1; i<=n+1; ++i){
		for(auto to: G1[i]){
			res[i][to.first] = 0;
			res[to.first][i] = 0;
		}
	}
	for(int i=1; i<=n+1; ++i){
		for(auto to: G2[i]){
			res[i][to] += 1;
		}
	}
	
	int tot = 0;
	memset(vis, 0, n+1);
	while(dfs(s, t)){
		tot++;
		memset(vis, 0, n+1);
	}
	return tot;
}

int main(){
	scanf(" %d %d %d", &n, &m, &c);
	int x, y, t;
	for(int i=0; i<m; ++i){
		scanf(" %d %d %d", &x, &y, &t);
		G1[x].push_back({y, t});
		G1[y].push_back({x, t});
	}
	vi comm(c);
	for(int i=0; i<c; ++i){
		scanf(" %d", &comm[i]);
	}

	makeDijTree();
	sort(comm.begin(), comm.end(), [](int a, int b){return d[a] < d[b];});
	
	int tot = 0;
	int i_i = 0;
	while(i_i < comm.size()){
		G2[n+1].clear();
		G1[n+1].clear();
		G1[n+1].push_back({comm[i_i], 0});
		G2[n+1].push_back(comm[i_i++]);
		while(i_i < comm.size() && d[comm[i_i]] == d[G2[n+1][0]]){
			G1[n+1].push_back({comm[i_i], 0});
			G2[n+1].push_back(comm[i_i++]);
		}
		tot += maxflow(n+1, 1);
	}
	printf("%d\n", tot);
}
















