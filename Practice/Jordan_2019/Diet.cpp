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

vi dead;
const ll inf = 1LL << 60;

// const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	ll a, b, badd = 0;
	ll alive = 0;
	// Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vll& as, vll& bs, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(as, bs, lo, mid);
			r = new Node(as, bs, mid, hi);
			b = min(l->b, r->b);
			a = l->a + r->a;
			alive = l->alive + r->alive;
		}
		else {
			a = as[lo];
			b = bs[lo];
			alive = 1;
		}
	}
	// int query(int L, int R) {
	// 	if (R <= lo || hi <= L) return -inf;
	// 	if (L <= lo && hi <= R) return val;
	// 	push();
	// 	return max(l->query(L, R), r->query(L, R));
	// }
	ll geta(int L, int R){
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return a;
		push();
		return l->geta(L,R) + r->geta(L,R);
	}
	ll getalive(int L, int R){
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return alive;
		push();
		return l->getalive(L, R) + r->getalive(L, R);
	}
	int dist(ll &amt, int L, int R){
		if (R <= lo || hi <= L) return 0;
		if (lo+1==hi) return (a <= amt ? hi : lo);
		if (amt >= a) return hi;
		else{
			if (amt <= l->a) return l->dist(amt, L, R);
			amt -= l->a;
			return r->dist(amt,L,R);
		}
	}

	// Adds to dead counter, returns highest hi
	int serve(ll amt, ll seen, int L, int R) {
		if (R <= lo || hi <= L) return -1;
		int right = 0;
		if (lo+1==hi){
			if (seen + a >= amt) return -1;
			if (b < amt) {
				dead.push_back(lo);
			}
			return hi;
		} else {
			push();
			if (l->b < amt){
				right = max(right, l->serve(amt, seen, L, R));
			}
			seen += l->a;
			if (seen < amt && r->b < amt){
				right = max(right, r->serve(amt, seen, L, R));
			}
		}
		return right;
	}
	// void set(int L, int R, int x) {
	// 	if (R <= lo || hi <= L) return;
	// 	if (L <= lo && hi <= R) mset = val = x, madd = 0;
	// 	else {
	// 		push(), l->set(L, R, x), r->set(L, R, x);
	// 		val = max(l->val, r->val);
	// 	}
	// }
	void set(int X, ll newa, ll newb) {
		if (X < lo || hi <= X) return;
		if (lo+1 == hi) {
			a = newa;
			b = newb;
			if (newa == 0 && newb == inf){
				alive = 0;
				// cout << "ded" << X << endl;
			} else {
				alive = 1;
			}
		} else {
			push();
			l->set(X, newa, newb);
			r->set(X, newa, newb);
			b = min(l->b, r->b);
			a = l->a + r->a;
			alive = l->alive + r->alive;
		}
	}

	void addtob(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			// if (mset != inf) mset += x;
			badd += x;
			b += x;
		}
		else {
			push();
			l->addtob(L, R, x), r->addtob(L, R, x);
			b = min(l->b, r->b);
		}
	}
	void push() {
		l->addtob(lo,hi,badd), r->addtob(lo,hi,badd), badd = 0;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> as(n), bs(n);
	rep(i,0,n) cin >> as[i];
	rep(i,0,n) cin >> bs[i];
	ll at = 0;
	rep(i,0,n){
		at += as[i];
		bs[i] += at;
	}
	Node T(as, bs, 0, n);

	int q;
	cin >> q;
	while(q--){
		// cout << "alive: " << T.alive << endl;
		int t;
		cin >> t;
		if (t==1) {
			ll x;
			cin >> x;
			dead.clear();
			int right = T.dist(x, 0, n);
			int _meh = T.serve(x, 0, 0, n);
			int nserve = T.getalive(right, n);
			cout << dead.size() << " " << nserve << endl;

			for(auto d : dead){
				// cout << d << endl;
				T.addtob(d+1, n, -as[d]);
				T.set(d, 0, inf);
				as[d] = 0;
				bs[d] = 0;
			}
		} else {
			ll a, b, c;
			cin >> a >> b >> c;
			c--;
			T.addtob(c+1, n, a-as[c]);
			as[c] = a;
			bs[c] = b;
			T.set(c, a, b);
		}
	}
}