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
const int maxn = 2e5+7;

bool poss = true;
int vis[maxn] = {0};
vi adj[maxn];

int ct[3] = {0};

void dfs(int v, int c){
	if (vis[v]){
		if (vis[v]!=c) poss = false;
		return;
	}
	vis[v] = c;
	ct[c]++;
	int n_c = (c==1 ? 2 : 1);
	for(auto e : adj[v]){
		dfs(e,n_c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vi is1, is2;
	rep(i,0,m){
		int a,b,c;
		cin >> a >> b >> c;
		if (c==0){
			is1.push_back(a);
			is1.push_back(b);
		} else if (c==2){
			is2.push_back(a);
			is2.push_back(b);
		} else {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}
	int tot = 0;
	for(auto e : is1){
		dfs(e,1);
	}
	for(auto e : is2){
		dfs(e,2);
	}
	tot += ct[2];
	rep(i,1,n+1){
		if (!vis[i]){
			ct[1]=ct[2]=0;
			dfs(i,1);
			tot += min(ct[1],ct[2]);
		}
	}
	if (poss){
		cout << tot << endl;
	} else {
		cout << "impossible" << endl;
	}
}
