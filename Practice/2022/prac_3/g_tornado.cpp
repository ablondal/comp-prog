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

struct Node{
	Node *l = 0, *r = 0;
	int lo, hi, layer=0, n_seg=0, layadd=0;
	Node(int L, int R): lo(L), hi(R) {}
	int query(int L, int R){
		if (L>=hi || R<=lo) return 0;
		else if (L<=lo && hi<=R) {
			return n_seg;
		}
		push();
		return l->query(L,R) + r->query(L,R);
	}
	void add(int L, int R, int x){
		if (L>=hi || R<=lo) return;
		else if (L<=lo && hi<=R) {
			layer += x;
		}else{
			int md = (hi+lo)/2;
			push();
			l->add(L,R,x); r->add(L,R,x);
		}
		if (layer>0) {
			n_seg = hi-lo;
		} else if (l){
			n_seg = l->n_seg + r->n_seg;
		} else {
			n_seg = 0;
		}
	}
	void push(){
		if (!l) {
			int md = (hi+lo)/2;
			l = new Node(lo,md);
			r = new Node(md,hi);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node T(0, 1e9+7);
	// T.add(5, 10, 1);
	// T.add(6, 12, 1);
	// cout << T.query(0, 1e9+7) << endl;
	// T.add(5, 10, -1);
	// cout << T.query(0, 1e9+7) << endl;
	// T.add(6, 12, -1);
	// cout << T.query(0, 1e9+7) << endl;
	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> boxs;
	rep(i,0,n){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		boxs.push_back({x1, y1, y2, 1});
		boxs.push_back({x2, y1, y2, -1});
	}
	sort(all(boxs));

	ll lastx = -1;
	ll tot = 0;
	for(auto [x, y1, y2, ch] : boxs){
		tot += (x-lastx)*T.query(0, 1e9+7);
		T.add(y1, y2, ch);
		lastx = x;
	}
	cout << tot << endl;
}