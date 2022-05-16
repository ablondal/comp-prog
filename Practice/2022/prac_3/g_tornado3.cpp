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
	Node *tl = 0, *tr = 0, *bl = 0, *br = 0;
	int x_lo, x_hi, y_lo, y_hi;
	int mset = 0;
	int n1s = 0;

	Node(int x_lo, int x_hi, int y_lo, int y_hi):x_lo(x_lo),x_hi(x_hi),y_lo(y_lo),y_hi(y_hi){} // Large interval of -inf
	
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