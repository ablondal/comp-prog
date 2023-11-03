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

struct query{
	int beg, en;
	multiset<int> trees;
	int done = false;
	bool add_tree(int h){
		auto it = trees.insert(h);

		if (it != trees.begin() && prev(it) != trees.begin()) {
			if (*prev(prev(it)) + *prev(it) > h) return done = true;
		}
		if (it != trees.begin() && next(it) != trees.end()) {
			if (*prev(it) + h > *next(it)) return done = true;
		}
		if (next(it) != trees.end() && next(next(it)) != trees.end()) {
			if (h + *next(it) > *next(next(it))) return done = true;
		}
		return false;
	}
	// Second method:
	// Works just as well, maybe 0.20 s slower

	// bool add_tree(int h){
	// 	trees.insert(h);
	// 	vector<int> ts(all(trees));
	// 	int n = sz(ts);
	// 	rep(i,0,n-2){
	// 		if (ts[i] + ts[i+1] > ts[i+2]) return done = true;
	// 	}
	// 	return false;
	// }
};

vector<int> done_qs;
vector<query> Qs;

struct Node {
	Node *l = 0, *r = 0;
	unordered_set<int> qs;
	int lo, hi;
	Node(int lo,int hi):lo(lo),hi(hi){}
	void add_q(int L, int R, int q){
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			qs.insert(q);
		}
		else {
			push(), l->add_q(L, R, q), r->add_q(L, R, q);
		}
	}
	void rm_q(int L, int R, int q){
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			qs.erase(q);
		}
		else {
			// Don't need to push, guaranteed the range has been explored before
			l->rm_q(L, R, q), r->rm_q(L, R, q);
		}
	}
	void add_tree(int x, int h){
		// Add tree to all ranges.
		// If tree completes a triangle, then add range to done vector
		// Recurse
		if (lo <= x && x < hi) {
			for(auto q: qs){
				bool res = Qs[q].add_tree(h);
				if (res) {
					done_qs.push_back(q);
				}
			}
			if (l) {
				l->add_tree(x,h); r->add_tree(x,h);
			}
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Get Trees and Queries
	int n, Q;
	cin >> n >> Q;
	vector<tuple<int, int, int>> trees(n);
	Qs.resize(Q);
	vector<pii> qin(Q), qout(Q);

	rep(i,0,n){
		auto &[a,b,c] = trees[i];
		cin >> a >> b >> c;
	}

	rep(i,0,Q){
		int xlo, ylo, xhi, yhi;
		cin >> xlo >> ylo >> xhi >> yhi;
		Qs[i].beg = ylo;
		Qs[i].en = yhi+1;

		qin[i] = {xlo, i};
		qout[i] = {xhi+1, i};
	}

	// Sort Queries by x value, both in and out
	sort(all(qin)); sort(all(qout));
	// Sort Trees by x value
	sort(all(trees));
	// Make array of active queries (in Qs[i].done)

	// Go through all x values for trees
	// For each tree, remove undone ranges, add ranges, then add tree
	// Remove any ranges that are done.
	Node T(0, 1000000007);
	int a=0, b=0;
	rep(t,0,n){
		auto [tx, ty, th] = trees[t];

		// Add all needed ranges
		while(b < sz(qin) && qin[b].first <= tx){
			int q = qin[b].second;
			T.add_q(Qs[q].beg, Qs[q].en, q);
			b++;
		}

		// Remove all unneeded ranges
		while(a < sz(qout) && qout[a].first <= tx){
			int q = qout[a].second;
			if (Qs[q].done != true) {
				T.rm_q(Qs[q].beg, Qs[q].en, q);
			}
			a++;
		}

		// Add tree
		T.add_tree(ty, th);

		// Remove done ranges
		for(auto q: done_qs){
			T.rm_q(Qs[q].beg, Qs[q].en, q);
		}
		done_qs.clear();
	}

	// Print answer using "done" list
	rep(q,0,Q){
		cout << Qs[q].done << endl;
	}
	
}