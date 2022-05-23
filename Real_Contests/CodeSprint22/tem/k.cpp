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
const int MX = 1e5+7;
const int BLK = 320;

struct RollbackUF {
	vi e; vector<pii> st;
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	int time() { return sz(st); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
	bool join(pii &e){
		return join(e.first, e.second);
	}
};
int n, m, K, t;

pii rebuild_and_query(vector<pii> &edges, int i){
	// cout << i << endl;
	RollbackUF UF(2*n+1);
	rep(j,0,i){
		UF.join(edges[2*j]);
		UF.join(edges[2*j+1]);
	}
	int nx = min(i + t + BLK, m);
	// cout << i << " " << nx << endl;
	// int t;
	rep(j,nx,m){
		UF.join(edges[2*j]);
		UF.join(edges[2*j+1]);
	}
	int T = UF.time();
	rep(j,i,min(m-t+1, i+BLK) ){
		rep(k,i,j){
			UF.join(edges[2*k]);
			UF.join(edges[2*k+1]);
		}
		rep(k,j+t,nx){
			UF.join(edges[2*k]);
			UF.join(edges[2*k+1]);
		}
		// cout << j << " " << UF.find(1) << " " << UF.find(2*K) << " " << UF.find(2*K+1) << endl;
		if (UF.find(0) == UF.find(2*K)) return {1, j};
		if (UF.find(0) == UF.find(2*K+1)) return {2, j};
		UF.rollback(T);
	}
	return {0, 0};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int n, m, k, t;
	cin >> n >> m >> K >> t;
	// t = 0;
	K--;
	vector<pii> edges;

	rep(i,0,m){
		int a, b;
		// a--; b--;
		string s;
		cin >> a >> b >> s;
		a--; b--;
		if (s[0] == 'c'){
			edges.push_back({2*a, 2*b});
			edges.push_back({2*a+1, 2*b+1});
		} else {
			edges.push_back({2*a+1, 2*b});
			edges.push_back({2*a, 2*b+1});
		}
	}

	for(int i=0; i<=m-t; i+=BLK){
		auto res = rebuild_and_query(edges, i);
		if (res.first == 0) continue;
		if (res.first == 1){
			cout << res.second+1 << " crewmate" << endl;
		} else {
			cout << res.second+1 << " imposter" << endl;
		}
		exit(0);
	}
	cout << -1 << endl;
}