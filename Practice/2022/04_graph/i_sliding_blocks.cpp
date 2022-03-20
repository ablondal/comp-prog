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
const int maxn = 4e5+7;

map<int, int> b_at_y[maxn];
map<int, int> b_at_x[maxn];
vi aft[maxn];
// set<pair<int, int>> blks;
vector<pair<int, int>> bs;

using dir=enum{U,D,L,R,N};
int ds[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int dfrom[maxn];

void DFS(int v, int d){
	auto [x, y] = bs[v];
	dfrom[v] = (d^1);
	if (d == D){
		auto it = b_at_x[x].find(y);
		it++;
		if (it!=b_at_x[x].end()){
			aft[v].push_back(it->second);
		}
	} else if (d == U){
		auto it = b_at_x[x].find(y);
		if (it != b_at_x[x].begin()){
			it--;
			aft[v].push_back(it->second);
		}
	} else if (d == L){
		auto it = b_at_y[y].find(x);
		if (it != b_at_y[y].begin()){
			it--;
			aft[v].push_back(it->second);
		}
	} else if (d == R){
		auto it = b_at_y[y].find(x);
		it++;
		if (it != b_at_y[y].end()){
			aft[v].push_back(it->second);
		}
	}
	rep(i,0,4){
		if ((i^1) == d) continue;
		auto [dx,dy] = ds[i];
		if (b_at_x[x+dx].count(y+dy)) {
			aft[v].push_back(b_at_x[x+dx][y+dy]);
			DFS(b_at_x[x+dx][y+dy], i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int Y,X,b;
	cin >> Y >> X >> b;
	// set<pair<int, int>> blks;
	// vector<pair<int, int>> bs(b);
	rep(i,0,b){
		int y,x;
		cin >> y >> x;
		// blks.insert({x,y});
		bs.push_back({x,y});
		b_at_x[x][y] = i;
		b_at_y[y][x] = i;
	}
	DFS(0, 5);
	queue<int> Q;
	vi ct(b+1,0);
	rep(i,1,b){
		for(auto e : aft[i]){
			ct[e]++;
			// cout << i << " -> " << e << endl;
		}
	}
	rep(i,1,b){
		if (ct[i]==0) Q.push(i);
	}
	vi ord;
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		ord.push_back(f);
		for(auto e : aft[f]){
			ct[e]--;
			if (ct[e]==0) Q.push(e);
		}
	}
	if (sz(ord)==b-1){
		cout << "possible" << endl;
		for(auto x : ord){
			if(dfrom[x] == U) cout << "^ " << bs[x].first << endl;
			else if (dfrom[x] == D) cout << "v " << bs[x].first << endl;
			else if (dfrom[x] == L) cout << "< " << bs[x].second << endl;
			else if (dfrom[x] == R) cout << "> " << bs[x].second << endl;
			// cout << x << endl;
			// cout << x << endl;
		}
	} else {
		cout << "impossible" << endl;
	}
}
