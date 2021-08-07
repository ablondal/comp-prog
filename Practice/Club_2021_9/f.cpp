#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e3+7;

vector<pii> adj[107];
vi par[107];

vi fadj[207];
int cap[207][207] = {{0}};
char V[207] = {0};

void dij(int s, int t, int n){
	priority_queue <pii, vector<pii>, greater<pii> > Q;
	Q.push({0,s});
	vi d(n+1,1e8+7);
	d[s] = 0;
	while(!Q.empty()){
		auto p = Q.top();
		Q.pop();
		int to = p.second;
		int dis = p.first;
		if (d[to]!=dis) continue;
		for(auto e: adj[to]){
			int newd = dis+e.second;

			// My dij modification for all min paths
			if (newd == d[e.first]){
				par[e.first].push_back(to);
			}else if(newd < d[e.first]){
				par[e.first].clear();
				par[e.first].push_back(to);
				d[e.first] = newd;
				Q.push({newd, e.first});
			}
		}
	}
}

int t;

// maxx is the minimum capacity along our path so far
// In other words, the most flow that we *could* allocate
int flow(int v, int maxx){
	if(v==t){
		return maxx;
	}
	V[v] = true;
	for(auto e : fadj[v]){
		if (V[e] || cap[v][e]<1) continue;
		int f = flow(e,min(maxx, cap[v][e]));
		if (f){
			cap[v][e] -= f;
			cap[e][v] += f;
			return f;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	rep(i,0,m){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}

	dij(0,n-1, n);

	rep(i,0,n){

		// Define the in -> out edges
		cap[i][i+102] = 1;

		// Make sure to put edges going back as well, for residual flow
		fadj[i].push_back(i+102);
		fadj[i+102].push_back(i);

		// Construct from the Dij graph
		for(auto e: par[i]){
			// Note we only create the forward edge
			// This is intentional, since we need min-cost path
			cap[e+102][i] = INF;
			
			fadj[e+102].push_back(i);
			fadj[i].push_back(e+102);
		}
	}
	int tot = 0;
	bool good = 1;
	t = n-1;
	while(true){
		// Never forget the memset
		memset(V, false, 207);

		int f = flow(102, INF);
		if (f) tot+=f;
		else break;
	}
	// In case there's a path straight to the airport
	if (tot < INF)
		cout << tot << endl;
	else cout << "IMPOSSIBLE" << endl;
}