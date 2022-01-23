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

vector<vector<pair<int, int>>> adj;
vector<bool> vis;

int DFS(int v, int t, ll lim){
	if (v == t) return true;
	for(auto e : adj[v]){
		if (vis[e.first]) continue;
		if (e.second < lim) continue;
		vis[e.first] = true;
		if (DFS(e.first, t, lim)) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, r;
	cin >> n >> m >> r;

	ll s = 0, t = m + n - 1;
	vector<pair<ll, pair<int, int>>> edges;

	vector<vector<pair<int, int>>> lanes(n);

	ll al, ale, adi;
	cin >> al >> ale >> adi;
	ale += adi;
	ll llen = ale-adi;

	ll override_min = r;

	rep(i,1,m){
		ll l, le, di;
		cin >> l >> le >> di;
		le += di;
		le = min(le, r);
		lanes[l].push_back({di, le});
	}
	rep(i,0,n){
		lanes[i].push_back({-1e9,0});
		lanes[i].push_back({r,1e9});
		sort(all(lanes[i]));
		for(int j=sz(lanes[i])-2; j>=0; --j){
			if (lanes[i][j].second == lanes[i][j+1].first) {
				lanes[i][j].second = lanes[i][j+1].second;
				lanes[i].erase(lanes[i].begin() + j+1);
			}
		}
	}


	ll tagbeg = 0;
	rep(i,0,n-1){
		rep(j,0,sz(lanes[i])-1){
			ll st = lanes[i][j].second;
			ll en = lanes[i][j+1].first;
			// cout << tagbeg + j << " " << st << " " << en << endl;

			if (i == al && st <= adi && ale <= en){
				s = tagbeg + j;
				override_min = min(adi-st, en-ale);
			}

			rep(j2,0,sz(lanes[i+1])-1){
				ll st2 = lanes[i+1][j2].second;
				ll en2 = lanes[i+1][j2+1].first;

				// cout << tagbeg + sz(lanes[i])-1 + j2 << " " << st2 << " " << en2 << endl;

				if (min(en, en2) - max(st, st2) >= llen){
					edges.push_back( {
						min(en, en2) - max(st, st2) - llen,
						{tagbeg+j, tagbeg+sz(lanes[i])-1+j2}
					});
				}
			}

		}
		tagbeg += sz(lanes[i])-1;
	}


	rep(j,0,sz(lanes[n-1])-1){
		ll st = lanes[n-1][j].second;
		ll en = lanes[n-1][j+1].first;
		if (en-st >= llen) {
			edges.push_back( {en-st-llen, {tagbeg + sz(lanes[n-1])-1, tagbeg + j}} );
		}
	}
	tagbeg += sz(lanes[n-1])-1;

	adj.resize(tagbeg+1);

	for(auto [d, ab] : edges){
		adj[ab.first].push_back({ab.second, d});
		adj[ab.second].push_back({ab.first, d});
	}

	ll lo = -1, hi = r;
	while(hi-lo > 1){
		ll md = (hi+lo)/2;
		vis.assign(tagbeg+1, 0);
		if (DFS(s, tagbeg, md)) {
			lo = md;
		} else {
			hi = md;
		}
		// cout << md << endl;
	}

	lo = min(lo, override_min);

	if (lo == -1){
		cout << "Impossible" << endl;
	} else {
		cout << lo/2.0 << endl;
	}
	
}