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

int UF[100007];
int dist[100007];

int find(int v){
	return UF[v]<0 ? v : find(UF[v]);
}

bool connect(int a, int b, int d){
	a = find(a);
	b = find(b);
	if (a==b) return false;
	if (a<b) swap(a, b);
	UF[b] += UF[a];
	UF[a] = b;
	dist[a] = d;
	return true;
}

void kruskal(vector<pair<int, pair<int, int>>> & edg){
	sort(all(edg));
	reverse(all(edg));
	int i = 0;
	while(i<edg.size()){
		auto [d, ab] = edg[i];
		auto [a, b] = ab;
		connect(a, b, d);
		i++;
	}
}

int dep[100007] = {0};
int getdep(int v){
	if (UF[v]<0) return 0;
	if (dep[v]) return dep[v];
	return dep[v] = getdep(UF[v])+1;
}

int safety(int a, int b) {
	int safe = 1e7;
	if (getdep(a) < getdep(b)){
		swap(a,b);
	}
	while(getdep(a)>getdep(b)){
		safe = min(safe, dist[a]);
		a = UF[a];
	}
	while(a != b && UF[a]>=0 && UF[b]>=0){
		safe = min(safe, dist[a]);
		safe = min(safe, dist[b]);
		a = UF[a];
		b = UF[b];
	}
	if (a!=b) return 1e9;
	return safe;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;

	int s = 0, t = m + n - 1;
	vector<pair<int, pair<int, int>>> edges;

	vector<vector<pair<int, int>>> lanes(n);

	int al, ale, adi;
	cin >> al >> ale >> adi;
	ale += adi;
	int llen = ale-adi;

	rep(i,1,m){
		int l, le, di;
		cin >> l >> le >> di;
		le += di;
		le = min(le, r);
		lanes[l].push_back({di, le});
	}
	rep(i,0,n){
		lanes[i].push_back({-1e9,0});
		lanes[i].push_back({r,1e9});
	}

	rep(i,0,n){
		sort(all(lanes[i]));
	}
	int tagbeg = 0;
	rep(i,0,n-1){
		rep(j,0,sz(lanes[i])-1){
			int st = lanes[i][j].second;
			int en = lanes[i][j+1].first;
			// cout << tagbeg + j << " " << st << " " << en << endl;

			if (i == al && st <= adi && ale <= en){
				s = tagbeg + j;
			}

			rep(j2,0,sz(lanes[i+1])-1){
				int st2 = lanes[i+1][j2].second;
				int en2 = lanes[i+1][j2+1].first;

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
		int st = lanes[n-1][j].second;
		int en = lanes[n-1][j+1].first;
		int md = en-st;
		if (en-st >= llen) {
			edges.push_back( {en-st-llen, {tagbeg + sz(lanes[n-1])-1, tagbeg + j}} );
		}
	}
	tagbeg += sz(lanes[n-1])-1;

	// cout << s << endl;

	// rep(i,0,sz(edges)){
	// 	cout << edges[i].first << " " << edges[i].second.first << " " << edges[i].second.second << endl;
	// }

	rep(i,0,tagbeg+7){
		UF[i] = -1;
	}

	kruskal(edges);
	int safe = safety(tagbeg, s);
	if (safe == 1e9) {
		cout << "Impossible" << endl;
	} else {
		cout << ((double)safe)/2.0 << endl;
	}

	
}