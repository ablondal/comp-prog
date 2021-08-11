#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

ll posx[507], posy[500];
ll dist[250007] = {0};

vi adj1[507];

vi adj[250007];

int UF[250007];
ll UW[250007];
int dep[250007] = {0};

int getdep(int v){
	if (dep[v]) return dep[v];
	if (UF[v]<0) return 1;
	return dep[v] = getdep(UF[v])+1;
}

inline int ind(int i, int j){
	return (i-1)+(j-1)*n;
}

int find(int x){
	return (UF[x]<0) ? x : find(UF[x]);
}

// int maxx(int a, int b){

// }

inline void merge(int a, int b, ll w){
	// printf("merging %d, %d with %lld\n", a, b, w);
	a = find(a);
	b = find(b);
	if (a==b) return;
	if (a<b){
		UF[a] += UF[b];
		UF[b] = a;
		UW[b] = w;
	} else {
		UF[b] += UF[a];
		UF[a] = b;
		UW[a] = w;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	rep(i,1,n+1){
		scanf("%lld%lld", posx+i, posy+i);
	}
	int m;
	scanf("%d", &m);
	rep(i,0,m){
		int a, b;
		scanf("%d%d", &a, &b);
		adj1[a].push_back(b);
		adj1[b].push_back(a);
	}

	rep(i,1,n+1){
		rep(j,1,n+1){
			auto v = ind(i,j);
			for(auto e : adj1[j]){
				adj[v].push_back(ind(i, e));
			}
			for(auto e : adj1[i]){
				adj[v].push_back(ind(e, j));
			}
		}
	}

	vector<pair<ll, int>> dists;
	dists.reserve(n*n);
	rep(i,0,250007) UF[i] = -1;
	rep(i,1,n+1){
		rep(j,1,n+1){
			dist[ind(i,j)] = (posx[i]-posx[j])*(posx[i]-posx[j]) +
						 (posy[i]-posy[j])*(posy[i]-posy[j]);
		 	dists.push_back({dist[ind(i,j)], ind(i,j)});
		}
	}

	sort(all(dists));
	for(int ii = dists.size()-1; ii>=0; --ii){
		auto& dd = dists[ii];
		int v = dd.second;
		for(auto e : adj[v]) {
			// printf("Merge %d and %d?\n", e, v);
			if (dist[e] >= dd.first) {
				merge(v, e, dd.first);
			}
		}
	}

	// cout << "Hi\n" << endl;

	rep(i,0,n*n){
		auto _ = getdep(i);
	}

	// cout << "uh\n" << endl;

	int l;
	scanf("%d", &l);
	rep(i,0,l){
		int a, b;
		scanf("%d%d", &a, &b);
		ll M = 1e18;
		int v1 = ind(a,b);
		int v2 = ind(b,a);
		// printf("%d %d\n", v1, v2);
		while(dep[v1] > dep[v2]){
			M = min(M, UW[v1]);
			v1 = UF[v1];
		}
		while(dep[v2] > dep[v1]){
			M = min(M, UW[v2]);
			v2 = UF[v2];
		}
				// printf("%d %d\n", v1, v2);

		while(v1 != v2){
			M = min(M, UW[v1]);
			v1 = UF[v1];
			M = min(M, UW[v2]);
			v2 = UF[v2];
		}
		// printf("%d %d\n", v1, v2);

		printf("%.8f\n", sqrt(M));
	}
	
}