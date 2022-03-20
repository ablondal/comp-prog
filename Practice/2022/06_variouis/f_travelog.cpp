#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

vector<pair<int, ll>> adj[200007];
vector<ll> times;
vi adij[200007];
vector<ll> d;
vector<int> ind;
vi p;

void dij(int s, int n){
	d.assign(200007, 1LL<<62);
	ind.assign(200007, -1);
	p.assign(200007, 0);

	using pii=pair<ll, int>;
	priority_queue<pii, vector<pii>, greater<pii>> Q;

	d[s] = 0;
	Q.push({0, s});
	while(!Q.empty()){
		auto [dd, v] = Q.top();
		Q.pop();
		if (dd != d[v]) continue;
		for(auto &[e, de] : adj[v]){
			if (d[e] > dd+de) {
				d[e] = dd+de;
				Q.push({d[e],e});
			}
		}
	}

	// Calculate travelog indices
	rep(i,1,n+1){
		int lo = 0, hi = times.size()-1;
		while(hi-lo>0){
			int md = (hi+lo)/2;
			if (times[md] <= d[i]) lo = md+1;
			else hi = md;
		}
		ind[i] = lo;
		// cout << d[i] << " " << ind[i] << endl;
	}

	// Form dij graph
	rep(i,1,n+1){
		for(auto &[e, de] : adj[i]){
			if (d[e] == d[i]+de){
				if (ind[i] == ind[e] || (ind[e] == ind[i]+1 && d[e] == times[ind[i]])){
					adij[i].push_back(e);
					// cout << i << "->" << e << endl;
				}
			}
		}
	}
}

int ww[200007] = {0};

int ways(int v, int n){
	if (ww[v]) return ww[v];
	if (v == n) return ww[v] = 1;

	int w = 0;
	for(auto e: adij[v]){
		int a = ways(e, n);
		if (a == -1) a = 0;
		if (a==1 && !p[v]) p[v] = e;
		w += a;
	}
	w = min(w, 2);
	if (w == 0) w = -1;
	return ww[v] = w;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, d;
	cin >> n >> m >> d;
	rep(i,0,m){
		ll u,v,h;
		cin >> u >> v >> h;
		adj[u].push_back({v, h});
	}
	rep(i,0,d){
		ll t;
		cin >> t;
		times.push_back(t);
	}
	sort(all(times));
	times.push_back(1LL<<62);

	dij(1, n);
	// cout << ind[n] << endl;
	if (ways(1, n) == -1 || ind[n] != times.size()-1){
		cout << 0 << endl;
	} else {
		if (ways(1, n) == 2){
			cout << 1 << endl;
		} else {
			vi pat;
			int f = 1;
			while(f){
				pat.push_back(f);
				f = p[f];
			}
			cout << sz(pat) << endl;
			for(auto e : pat){
				cout << e << endl;
			}
		}
	}
}