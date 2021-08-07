#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 3e5+7;

int ti=0, to=0;
int tin[MAXN], tout[MAXN];

vi adj_line[MAXN];
vi adj_noli[MAXN];

int M = 0;

void DFS_noli(int v, int p){
	tin[v] = ti++;
	for(auto e : adj_noli[v]){
		if (e==p) continue;
		DFS_noli(e, v);
	}
	tout[v] = to++;
}


void DFS(int v, int p, set<pair<int, int>> &segs) {
	pair<int, int> seg = {tin[v], tout[v]};
	auto it = segs.lower_bound(seg);
	auto it2 = it;
	// cout << "hi1" << endl;
	// it2--;
	// cout << "hi2" << endl;
	if (it != segs.begin() && (--it2)->second > seg.second){
		auto s2 = *it2;
		segs.erase(it2);
		segs.insert(seg);
		for(auto e : adj_line[v]){
			if (e==p) continue;
			DFS(e, v, segs);
		}
		segs.erase(segs.find(seg));
		segs.insert(s2);
	}else if (it != segs.end() && it->first < seg.second){
		for(auto e : adj_line[v]){
			if (e==p) continue;
			DFS(e, v, segs);
		}
	}else{
		segs.insert(seg);
		M = max(M, (int)segs.size());
		for(auto e : adj_line[v]){
			if (e==p) continue;
			DFS(e, v, segs);
		}
		segs.erase(segs.find(seg));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		rep(i,1,n+1){
			adj_line[i].clear();
			adj_noli[i].clear();
		}
		rep(i,2,n+1){
			int p;
			cin >> p;
			adj_line[i].push_back(p);
			adj_line[p].push_back(i);
		}
		rep(i,2,n+1){
			int p;
			cin >> p;
			adj_noli[i].push_back(p);
			adj_noli[p].push_back(i);
		}
		DFS_noli(1,0);
		set<pair<int, int>> segs;
		M = 0;
		DFS(1,0,segs);
		cout << M << endl;
	}
}