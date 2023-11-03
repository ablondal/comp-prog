#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

struct custom_hash {
	// From https://codeforces.com/blog/entry/62393
    const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(pii x) const {
    	return splitmix64( x.first ^ (x.second>>1) + FIXED_RANDOM );
    }
};

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
};

struct Tree {
	vector<vector<pair<int, int>>> s;
	vector<vector<int>> child;
	int n;
	Tree(int n = 0) : s(2*n), n(n), child(2*n) {}
	void add_edge(int b, int e, pair<int, int> ab){
		for (b +=n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) {
				s[b].push_back(ab);
				b++;
			}
			if (e % 2) {
				e--;
				s[e].push_back(ab);
			}
		}
	}
	void calc_parents(){
		rep(i,1,2*n){
			child[i/2].push_back(i);
		}
	}
};

gp_hash_table<pair<int,int>, int, custom_hash> E;
int n, m, k, dd;
vector<int> ans;

void dfs(Tree &T, RollbackUF &UF, int cmp, int v){
	// cout << v << endl;
	int t = UF.time();
	for(auto& [a, b]: T.s[v]){
		if (UF.join(a, b)) cmp--;
	}
	if (v >= dd){
		ans.push_back(cmp);
	}
	for(auto &c: T.child[v]){
		dfs(T, UF, cmp, c);
	}
	UF.rollback(t);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	// edge (a, b) from [start to end)
	vector<tuple<int, int, int, int>> events;

	// Get all events
	rep(i,0,m){
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a,b);
		E[{a, b}] = 0;
	}
	rep(i,0,k){
		int t, a, b;
		cin >> t >> a >> b;
		if (a > b) swap(a, b);

		if (t==1) {
			E[{a, b}] = i+1;
		} else {
			events.push_back({a, b, E[{a, b}], i+1});
			E[{a, b}] = -1;
		}
	}
	// Get the events left over
	for(auto [ab, t]: E){
		auto [a, b] = ab;
		if (t != -1){
			events.push_back({a, b, t, k+1});
		}
	}

	dd=1;
	while(dd < k+1) dd <<= 1;

	Tree T(dd);
	T.calc_parents();
	RollbackUF UF(n+1);

	for(auto [a,b,c,d]: events){
		T.add_edge(c, d, {a,b});
	}

	dfs(T, UF, n, 1);
	rep(i,0,k+1){
		cout << ans[i] << " ";
	}
	cout << endl;
}