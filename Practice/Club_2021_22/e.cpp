#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 5e5+7;

vi adj[MAXN];

vi times;

void DFS(int v, int p, int d){
	if (adj[v].size()==1){
		times.push_back(d);
	}
	for(auto e : adj[v]){
		if (e==p) continue;
		DFS(e,v,d+1);
	}
	// sort(all(times));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n-1){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int M = 0;
	for(auto e : adj[1]){
		times.clear();
		DFS(e, 1, 0);
		sort(all(times));
		for(int i=0; i<times.size(); ++i){
			M = max(M, sz(times)+times[i]-i);
		}
	}

	cout << M << endl;
}