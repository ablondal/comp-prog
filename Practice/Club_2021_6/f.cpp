#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 200007;

vector<pii> adj[MAXN];
vector<pair<int, pii>> edges;
vector<pair<int, pii>> ed;
set<int> intree;
int F[MAXN] = {0};
int find(int v){
	return F[v]==0 ? v : F[v] = find(F[v]);
}

ll min_span_tree(vector<pair<int, pii>> &ed, int n){
	ll tot = 0;
	// cout << "HI" << endl;
	sort(all(ed));
	for(int i=0; i<sz(ed); ++i){
		int w = ed[i].first;
		int v = ed[i].second.first;
		int u = ed[i].second.second;
		// cout << w << " " << v << " " << u << endl;
		int a = find(u);
		int b = find(v);
		// cout << a << " " << b << endl;
		if (a==b) continue;
		F[a] = b;
		n--;
		// cout << n << endl;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		intree.insert(i);
		// cout << n << endl;
		tot += w;
		// cout << tot << endl;
		if(n==1)break;
	}
	return tot;
}

int P[MAXN][20] = {{0}};
int M[MAXN][20] = {{0}};
int dep[MAXN] = {{0}};

void DFS(int v, int p, int w, int dd){
	dep[v] = dd;
	P[v][0] = p;
	M[v][0] = w;
	rep(i,1,20){
		P[v][i] = P[P[v][i-1]][i-1];
		M[v][i] = max(M[v][i-1], M[P[v][i-1]][i-1]);
	}
	for(auto &e : adj[v]){
		if (e.first==p) continue;
		DFS(e.first, v, e.second, dd+1);
	}
}

int getparent(int a, int b){
	if (dep[a]<dep[b]) swap(a,b);
	int ddiff = dep[a]-dep[b];
	int am = 0;
	int bm = 0;
	for(int i=19; i>=0; --i){
		if ( (1<<i) <= ddiff){
			ddiff -= 1<<i;
			am = max(am, M[a][i]);
			a = P[a][i];
		}
	}
	if (a==b){
		return max(am, bm);
	}
	for(int i=19; i>=0; --i){
		if (P[a][i] != P[b][i]){
			am = max(am, M[a][i]);
			a = P[a][i];
			bm = max(bm, M[b][i]);
			b = P[b][i];
		}
	}
	am = max(am, M[a][0]);
	bm = max(bm, M[b][0]);

	return max(am, bm);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	edges.resize(m);
	ed.resize(m);
	rep(i,0,m){
		// int u,v,w;
		// cin >> u >> v >> w;
		// edges[i]= ed[i] = {w, {u,v}};

		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
		ed[i].first = edges[i].first;
		ed[i].second.first = edges[i].second.first;
		ed[i].second.second = edges[i].second.second;
		// adj[u].push_back(w);
		// adj[v].push_back(u);
	}
	ll tot = min_span_tree(ed, n);
	DFS(1, 1, 0, 0);

	rep(i,0,m){
		// if (intree.count(i)) cout << tot << endl;
		// else{
			ll weight = tot
				+edges[i].first
				-getparent(edges[i].second.first, edges[i].second.second);
			cout << weight << endl;
		// }
	}

	return 0;
}