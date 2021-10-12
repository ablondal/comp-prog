#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char vis[500] = {0};

vi adj[500];

vi is, ns;

void DFS(int i){
	if (vis[i]) return;
	vis[i] = true;
	is.push_back(i);
	for(auto e : adj[i]){
		DFS(e);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi p(n);
	rep(i,0,n) cin >> p[i];
	rep(i,0,n){
		string s;
		cin >> s;
		rep(j,0,n){
			if (s[j] == '1'){
				adj[i].push_back(j);
			}
		}
	}
	rep(i,0,n){
		if (!vis[i]) {
			is.clear();
			ns.clear();
			DFS(i);
			for(auto ii : is){
				ns.push_back(p[ii]);
			}
			sort(all(ns));
			sort(all(is));
			rep(i,0,sz(ns)){
				p[is[i]] = ns[i];
			}
		}
	}
	for(auto e:p){
		cout << e << " ";
	}
	cout << endl;
}