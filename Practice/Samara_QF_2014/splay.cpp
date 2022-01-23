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

#define nil ((node*)nn)
ll* nn = new ll[64]();

typedef char T;
struct SplayTree{
	struct node;
	typedef node* nd;
	nd head = nil;
	int siz = 0;

	SplayTree(vector<T>& vt) {
		auto cur = head = new node(vt[0]);
		rep(i,1,sz(vt)){
			cur->R = new node(vt[i]);
			cur->push();
			cur = cur->R;
		}
		splay(cur);
		head = cur;
		siz = vt.size();
		DFS_print();
	}

	SplayTree(nd head, int siz): head(head), siz(siz) {}

	struct node{
		node *L, *R;
		bool rev;
		int siz;
		T val;
		node(T a): L(nil), R(nil), rev(0), siz(1), val(a) {}

		void push(int dir=0){
			if (this == nil) break;
			if (dir) (dir==1 ? R : L)->push(dir);
			siz = L->siz+R->siz+1;
			if (rev) {
				swap(L, R);
				rev = 0;
				R->rev^=1;
				L->rev^=1;
			}
		}
	};

	void DFS_print( nd x = 0 ){
		if (x==0) x = head;
		if (x==nil) return;
		
		if (x->L != nil){
			cout << "L ";
			DFS_print( x->L );
		}
		cout << x->val << " ";
		if (x->R != nil){
			cout << "R ";
			DFS_print( x->R );
		}
		if (x==head) cout << endl;
	}

	nd leftrot( nd x ){ // call on parent
		nd y = x->R; x->R = y->L; y->L = x;
		x->push(); y->push();
		return y;
	}
	nd rightrot( nd x ){
		nd y = x->L; x->L = y->R; y->R = x;
		x->push(); y->push();
		return y;
	}

	void splay( nd& t, int n ){
		if (t==nil) return;
		node head, *L = &head, *R = &head;
		while(true){
			if (t->L->siz == n) break; // Done
			else if (t->L->siz > n) {
				if (t->L != nil && t->L->L->siz > n) {
					t = rightrot( t );
				}
				if (t->L == nil) break;
				R->L=t; R=t; t=t->L;
			} else {
				if (t->R != nil && t->R->L->siz < n) {
					t = leftrot( t );
				}
				if (t->R == nil) break;
				L->R=t; L=t; t=t->R;
			}
		}
		L->R = t->L; R->L = t->R;
		t->L = head.R; t->R = head.L;

		t->L->push(1);
		t->R->push(-1);
		t->push();
	}

	// void splay( nd x, int n ){
	// 	cout << "splaying" << endl;
	// 	while(x->P != nil){
	// 		if (x->P->P == nil) {
	// 			if (x->P->L == x) rightrot(x->P);
	// 			else leftrot(x->P);
	// 		}
	// 		if (x->P->L == x) {
	// 			if (x->P->P->L == x->P) {
	// 				rightrot(x->P->P);
	// 				rightrot(x->P);
	// 			} else {
	// 				rightrot(x->P);
	// 				leftrot(x->P);
	// 			}
	// 		} else {
	// 			if (x->P->P->L == x->P) {
	// 				leftrot(x->P);
	// 				rightrot(x->P);
	// 			} else {
	// 				leftrot(x->P->P);
	// 				leftrot(x->P);
	// 			}
	// 		}
	// 		DFS_print();
	// 	}
	// 	head = x;
	// }

	node* nth(int n){ // 0 to siz-1
		splay(head, n);
		return (head->L->siz == n) ? head : nil;
	}

	// node* insert(int pos, T x){ // Supports pos in [1, cur_size+1]
	// 	auto n = nth(pos-1);
	// 	nd y = new node(x);
	// 	y->L = head;
	// 	if (n != nil) {
	// 		y->R = head->R;
	// 		head->R = nil;
	// 		head->push();
	// 	}
	// 	y->push();
	// 	return head = y;
	// }

	// void reverse(int l, int r){
	// 	g

	// 	auto ln = nth(l-1);
		
	// 	if (r < siz) {
	// 		SplayTree sp2 (head->R, head->R->siz);
	// 		ln->R->P = nil;
	// 		auto rn = sp2.nth(r-l+2);
	// 		rn->L->rev ^= 1;
	// 		rn->P = ln;
	// 	} else {
	// 		ln->R->rev ^= 1;
	// 	}
	// }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, r;
	cin >> n >> l >> r;
	string s;
	cin >> s;
	vector<char> vs(all(s));
	SplayTree ST(vs);
	ST.DFS_print();
	int m;
	cin >> m;
	while(m--){
		char q;
		cin >> q;
		if (q=='S'){
			char x,y;
			int dir = (y == 'R') ? 1 : -1;
			cin >> x >> y;
			if (x=='L') l+=dir;
			else r+=dir;
		} else if (q=='R') {
			ST.reverse(l, r);
		} else {
			char x;
			cin >> x;
			if (x=='L') cout << ST.nth(l)->val << endl;
		}
		ST.DFS_print();
	}

}