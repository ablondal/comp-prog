#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef struct{
	vector<pii> funcs;
	vector<double> inter;
	bool rdy = false;
} hull;
const int MAXN = 1e5+7;
const ll INF = 1e18+7;

hull t[4*MAXN];
vi adj[MAXN];

int tin[MAXN], tout[MAXN], timer = 0, order[MAXN];
ll as[MAXN], bs[MAXN], mincost[MAXN];

double isect(pii a, pii b){
	return (double)(b.first - a.first) / (a.second - b.second);
}

ll optimize(hull &H, ll x){
	// printf("Optimizing with hull:");
	// for(auto h : H.funcs) printf(" (%lld, %lld)", h.first, h.second);
	// printf("\nat point %lld.\n", x);
	int lo = 0, hi = sz(H.inter);
	while(hi-lo > 1){
		int mid = (hi+lo)>>1;
		if (H.inter[mid] <= x) lo = mid;
		else hi = mid;
	}
	// int i = upper_bound(all(H.inter), x) - H.inter.begin();
	return H.funcs[lo].second * x + H.funcs[lo].first;
}

void try_merge(int v){
	if (v == 0 || t[v].rdy == true) return;
	if (!t[2*v].rdy || !t[2*v+1].rdy) return;
	vector<pii>& a = t[v].funcs;
	vector<pii>& b = t[2*v].funcs;
	vector<pii>& c = t[2*v+1].funcs;

	vector<double>& ai = t[v].inter;
	vector<double>& bi = t[2*v].inter;
	vector<double>& ci = t[2*v+1].inter;

	int bj = 0, cj = 0;
	while(bj < sz(b) || cj < sz(c)){
		pii curr;
		if (bj == sz(b)){
			curr = c[cj++];
		}else if (cj == sz(c)){
			curr = b[bj++];
		}else if (
			make_pair(b[bj].second, -b[bj].first) > make_pair(c[cj].second, -c[cj].first)
		){
			curr = b[bj++];
		}else{
			curr = c[cj++];
		}

		if (sz(a) == 0){
			a.push_back(curr);
			ai.push_back(-INF);
		} else {
			if (curr.second == a.back().second) continue;
			while( isect(curr, a.back()) < ai.back() ){
				ai.pop_back();
				a.pop_back();
			}
			ai.push_back(isect(curr, a.back()));
			a.push_back(curr);
		}
	}
	// printf("Merged into %v:");
	// for(auto h : t[v].funcs) printf(" (%lld, %lld)", h.first, h.second);
	// printf("\n");
	t[v].rdy = true;
	try_merge(v/2);
}

void update(int v, int tl, int tr, int pos, pii new_line){
	// printf("update(%d, %d, %d, %d, (%lld, %lld))\n", v, tl, tr, pos, new_line.first, new_line.second);
	if (tl == tr) {
		t[v].funcs.push_back(new_line);
		t[v].inter.push_back(-INF);
		t[v].rdy = true;
		try_merge(v/2);
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm){
			update(v*2, tl, tm, pos, new_line);
		} else {
			update(v*2+1, tm+1, tr, pos, new_line);
		}
	}
}

ll get_min(int v, int tl, int tr, int l, int r, ll x){
	// printf("get_min called with %d, %d, %d, %d, %d, %lld\n", v, tl, tr, l, r, x);
	if (l>r) return INF;
	if (l==tl && r==tr) return optimize(t[v], x);
	int tm = (tl+tr) / 2;
	return min(
		get_min(v*2, tl, tm, l, min(r, tm), x),
		get_min(v*2+1, tm+1, tr, max(l, tm+1), r, x)
	);
}

void DFS(int v, int p){
	tin[v] = timer;
	for(auto e : adj[v]){
		if (e==p) continue;
		DFS(e, v);
	}
	order[timer] = v;
	tout[v] = timer;
	timer++;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,1,n+1) cin >> as[i];
	rep(i,1,n+1) cin >> bs[i];
	rep(i,1,n){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(1, 0);
	rep(i,0,n){
		int v = order[i];
		// cout << "Working with " << v << endl;
		if (tin[v] == tout[v]){
			mincost[v] = 0;
			pii new_line = {mincost[v], bs[v]};
			update(1, 0, n-1, tout[v], new_line);
		} else {
			// printf("Getting min(%d, %d, %d, %d, %d, %lld)\n", 1, 0, n-1, tin[v], tout[v]-1, as[v]);
			mincost[v] = get_min(1, 0, n-1, tin[v], tout[v]-1, as[v]);
			pii new_line = {mincost[v], bs[v]};
			update(1, 0, n-1, tout[v], new_line);
		}
	}
	rep(i,1,n+1){
		cout << (i==1 ? "" : " ") << mincost[i];
	}
	cout << endl;
}