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
const int segsz = 316;
const int siz = 1e5+7;

const int inf = 2e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	int mset = 0;
	int madd = 0;

	int tot = 0;
	int n1s = 0;

	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf

	// int queryn1s(int L, int R) {
	// 	if (R <= lo || hi <= L) return 0;
	// 	if (L <= lo && hi <= R) return n1s;
	// 	push();
	// 	return max(l->query(L, R), r->query(L, R));
	// }

	// void set(int L, int R, int x) {
	// 	if (R <= lo || hi <= L) return;
	// 	if (L <= lo && hi <= R) mset = val = x, madd = 0;
	// 	else {
	// 		push(), l->set(L, R, x), r->set(L, R, x);
	// 		val = max(l->val, r->val);
	// 	}
	// }
	
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			// tot += (hi-lo)*x;
			if (madd > 0) {
				n1s = r-l;
			} else {
				n1s = l->n1s + r->n1s;
			}
		} else {
			push(), l->add(L, R, x), r->add(L, R, x);
			// tot = l->tot + r->tot;
			n1s = l->n1s + r->n1s;
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		// if (mset != inf)
		// 	l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
		n1s = l->n1s + r->n1s;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

}