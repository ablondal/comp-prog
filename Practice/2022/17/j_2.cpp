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

typedef vector<bitset<200>> vb;
struct Maxclique {
	double limit=0.025, pk=0;
	struct Vertex{int i, d=0; };
	typedef vector<Vertex> vv;
	vb e;
	vv V;
	vector<vi> C;
	vi qmax, q, S, old;
	void init(vv& r) {
		for(auto &v: r) v.d=0;
			for(auto& v:r) for(auto j : r) v.d += e[v.i][j.i];
			sort(all(r), [](auto a, auto b){return a.d > b.d;});
		int mxD = r[0].d;
		rep(i,0,sz(r)) r[i].d=min(i, mxD) + 1;
	}
	void expand(vv &R, int lev=1){
		S[lev] += S[lev-1] - old[lev];
		old[lev] = S[lev-1];
		while(sz(R)){
			if (sz(q) + R.back().d <= sz(qmax)) return;
			q.push_back(R.back().i);
			vv T;
			for(auto v:R) if (e[R.back().i][v.i]) T.push_back({v.i});
			if (sz(T)){
				if (S[lev]++ / ++pk < limit) init(T);
				int j=0, mxk = 1, mnk = max(sz(qmax)-sz(q)+1, 1);
				C[1].clear(), C[2].clear();
				for(auto v:T) {
					int k=1;
					auto f = [&](int i) {return e[v.i][i];};
					while(any_of(all(C[k]), f)) k++;
					if (k>mxk) mxk = k, C[mxk+1].clear();
					if (k<mnk) T[j++].i = v.i;
					C[k].push_back(v.i);
				}
				if (j>0) T[j-1].d = 0;
				rep(k, mnk, mxk+1) for(int i: C[k])
					T[j].i = i, T[j++].d = k;
				expand(T, lev+1);
			} else if (sz(q) > sz(qmax)) qmax = q;
			q.pop_back(), R.pop_back();
		}
	}
	vi maxClique() {init(V), expand(V); return qmax; }
	Maxclique(vb conn) : e(conn), C(sz(e)+1), S(sz(C)), old(S){
		rep(i,0,sz(e)) V.push_back({i});
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, n;
	cin >> k >> n;
	if (k*5 <= n) {
		cout << "possible" << endl;
		exit(0);
	}
	vb M(n);
	rep(i,0,n) rep(j,0,n){
		if (i != j) M[i][j] = true;
	}
	rep(i,0,n){
		int ct;
		cin >> ct;
		rep(j,0,ct){
			int a;
			cin >> a;
			M[i][a-1] = false;
		}
	}
	Maxclique mc(M);
	auto res = mc.maxClique();
	// for(auto a : res){
	// 	cout << a << endl;
	// }
	cout << (sz(res) >= k ? "possible" : "impossible") << endl;

}