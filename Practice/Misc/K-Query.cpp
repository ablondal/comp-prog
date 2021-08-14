#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e9+7;

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, val = 0;
	Node(int lo, int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(Node* l, Node* r, int lo, int hi, int val):l(l), r(r), lo(lo), hi(hi), val(val){}

	int query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}

	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
	}

	Node* update(int pos, int x) {
		if (lo > pos || hi <= pos) return this;
		if (lo==pos && hi==pos+1) return new Node(nullptr, nullptr, lo, hi, val+1);
		push();
		return new Node(l->update(pos, x), r->update(pos, x), lo, hi, val+x);
	}
};

// Node* add(Node* curr, int pos, int x) {
// 	if (curr->lo > pos || curr->hi <= pos) return curr;
// 	return new Node(add(curr->l, pos, x), add(curr->r, pos, x), curr->lo, curr->hi, curr->val+x);
// }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	scanf("%d", &n);
	vector<Node*> nodes;
	nodes.push_back(new Node(0, MAXN));
	// cout << "HI" << endl;
	rep(i,0,n){
		int a;
		scanf("%d", &a);
		nodes.push_back(nodes.back()->update(a, 1));
	}
	int q;
	scanf("%d", &q);
	while(q--){
		int i,j,k;
		scanf("%d%d%d", &i, &j, &k);
		printf("%d\n", nodes[j]->query(k+1,MAXN) - nodes[i-1]->query(k+1, MAXN));
	}
}