#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct T{
	ll cost = 0;
	ll cones = 0;
};

const ll inf = 1e18;
struct Node {
	Node *l = 0, *r = 0;
	ll lo, hi, madd = 0;
	ll mset = inf;
	T val;
	Node(int lo, int hi) : lo(lo), hi(hi) {
		if (lo < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid);
			r = new Node(mid+1, hi);
		}
	}
	ll querycones(int L, int R) {
		if (R < lo || hi < L) return 0;
		if (L <= lo && hi <= R) return val.cones;
		push();
		return l->querycones(L, R)+r->querycones(L, R);
	}
	ll querycost(int L, int R) {
		if (R < lo || hi < L) return 0;
		if (L <= lo && hi <= R) return val.cost;
		push();
		return l->querycost(L, R)+r->querycost(L, R);
	}
	void set(ll L, ll R, ll x) {
		if (R < lo || hi < L) return;
		if (L <= lo && hi <= R) {
			mset = x;
			madd = 0;
			val.cones = x * (hi-lo+1);
			val.cost = x * ((hi-lo+1)*(hi+lo))/2;
		} else {
			push();
			l->set(L, R, x);
			r->set(L, R, x);
			val.cones = l->val.cones + r->val.cones;
			val.cost = l->val.cost + r->val.cost;
		}
	}
	void add(ll L, ll R, ll x) {
		if (R < lo || hi < L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val.cones += x * (hi-lo+1);
			val.cost += x * ((hi-lo+1)*(hi+lo))/2;
		} else {
			push();
			l->add(L, R, x);
			r->add(L, R, x);
			val.cones = l->val.cones + r->val.cones;
			val.cost = l->val.cost + r->val.cost;
		}
		// cout << lo << " " << hi << " " << val.cones << " " << val.cost << endl;
	}
	void push() {
		// if (!l) {
		// 	int mid = lo + (hi - lo)/2;
		// 	l = new Node(lo, mid);
		// 	r = new Node(mid, hi);
		// }
		if (mset != inf) {
			l->set(lo,hi,mset);
			r->set(lo,hi,mset);
			mset = inf;
		} else if (madd) {
			l->add(lo,hi,madd);
			r->add(lo,hi,madd);
			madd = 0;
		}
	}
	ll querylthcost(int x) {
		if (lo == hi) return lo;
		push();
		if (x <= l->val.cones) {
			return l->querylthcost(x);
		} else {
			x -= l->val.cones;
		}
		if (r->val.cones < x) {
			return -1;
		}
		return r->querylthcost(x);
	}
	ll buylow(ll x) {
		if (val.cones == x) {
			ll res = val.cost;
			set(lo, hi, 0);
			return res;
		}
		if (lo == hi) {
			val.cones -= x;
			val.cost -= x*lo;
			return x*lo;
		}
		push();
		ll tot = 0;
		int y = min(x, l->val.cones);
		tot += l->buylow(y);
		x -= y;

		if (x) {
			y = min(x, r->val.cones);
			tot += r->buylow(y);
			x -= y;
		}
		val.cones = l->val.cones + r->val.cones;
		val.cost = l->val.cost + r->val.cost;
		return tot;
	}
	ll buyhigh(ll x) {
		if (val.cones == x) {
			ll res = val.cost;
			set(lo, hi, 0);
			return res;
		}
		if (lo == hi) {
			val.cones -= x;
			val.cost -= x*lo;
			return x*lo;
		}
		push();
		ll tot = 0;
		int y = min(x, r->val.cones);
		tot += r->buyhigh(y);
		x -= y;

		if (x) {
			y = min(x, l->val.cones);
			tot += l->buyhigh(y);
			x -= y;
		}
		val.cones = l->val.cones + r->val.cones;
		val.cost = l->val.cost + r->val.cost;
		return tot;
	}
	ll buyamt(ll& x){
		// cout << lo << " " << hi << endl;
		if (val.cost <= x) {
			ll res = val.cones;
			x -= val.cost;
			set(lo, hi, 0);
			return res;
		}
		if (lo == hi) {
			ll ncones = min(val.cones, x / lo);
			val.cones -= ncones;
			val.cost -= ncones*lo;
			x -= ncones*lo;
			return ncones;
		}
		push();
		ll tot = 0;
		// int y = min(x, l->val.cost);
		tot += l->buyamt(x);
		// x -= ;
		if (x >= r->lo) {
			// y = min(x, r->val.cost);
			tot += r->buyamt(x);
			// x -= y;
		}
		val.cones = l->val.cones + r->val.cones;
		val.cost = l->val.cost + r->val.cost;
		return tot;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node Tree(0, 2e6+7);
	int N;
	cin >> N;
	while(N--){
		string op;
		cin >> op;
		if (op == "ADD"){
			ll k, p;
			cin >> k >> p;
			Tree.add(p, p, k);
		} else if (op == "ADDRANGE"){
			ll l, r;
			cin >> l >> r;
			Tree.add(l, r, 1);
		} else if (op == "NUMCONES"){
			cout << Tree.val.cones << endl;
		} else if (op == "TOTALCOST"){
			cout << Tree.val.cost << endl;
		} else if (op == "PRINT"){
			rep(i,1,10) {
				cout << Tree.querycones(i,i) << " " << Tree.querycost(i,i) << endl;
			}
		} else if (op == "COST"){
			ll L;
			cin >> L;
			cout << Tree.querylthcost(L) << endl;
		} else if (op == "BUYLOW"){
			ll L;
			cin >> L;
			cout << Tree.buylow(L) << endl;
		} else if (op == "BUYHIGH"){
			ll R;
			cin >> R;
			cout << Tree.buyhigh(R) << endl;
		} else if (op == "BUYAMT") {
			ll L;
			cin >> L;
			cout << Tree.buyamt(L) << endl;
		}
	}
}