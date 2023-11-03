#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5+7;

const int inf = 1e9;
struct Node{
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo, int hi): lo(lo), hi(hi) {}
	Node(vi &v, int lo, int hi): lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi-lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x){
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		} else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi-lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
		else if (madd)
			l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
	}
};

int gx;

struct line{
	int x0, x1, y0, y1;
	int idex;
	int fin() const {
		return (y0 < y1 ? x0 : x1);
	}
	double at() const {
		return y0 + (y1-y0) * (gx-x0) / ((double)(x1 - x0));
	}
	bool operator< (const line& b) const {
		return at() < b.at();
	}
};

line ls[MX];

set<line> S;

vi adj[MX];

int main(){
	cin.tie(0) ->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vector<pii> ivals;
	rep(i,1,n+1){
		int x0,y0,x1,y1;
		cin >> x0 >> y0 >> x1 >> y1;
		if (x1 < x0) {
			swap(x0, x1);
			swap(y0, y1);
		}
		ls[i] = {x0, x1, y0, y1, i};
		ivals.push_back({x0, -i});
		ivals.push_back({x1, i});
	}
	int xfinal;
	cin >> xfinal;
	sort(all(ivals));
	rep(i,0,sz(ivals)){
		gx = ivals[i].first;
		if (ivals[i].second > 0) {
			S.erase(ls[ivals[i].second]);
		} else {
			auto [it, _] = S.insert(ls[-ivals[i].second]);
			auto it2 = it;
			if (it2 != S.begin()){
				it2--;
				adj[it2->idex].push_back(it->idex);
			}
			it2 = it;
			it2++;
			if (it2 != S.end()){
				adj[it->idex].push_back(it2->idex);
			}
		}
	}
	Node Tree(-1000007, 1000007);
	vi indeg(n+1, 0);
	rep(i,1,n+1){
		for(auto e : adj[i]){
			indeg[e]++;
		}
	}
	queue<int> Q;
	rep(i,1,n+1){
		if (indeg[i] == 0) {
			Q.push(i);
		}
	}
	while(!Q.empty()){
		auto f = Q.front();
		Q.pop();
		for(auto r : adj[f]) {
			indeg[r]--;
			if (indeg[r] == 0) {
				Q.push(r);
			}
		}
		int to = Tree.query(ls[f].fin(), ls[f].fin()+1);
		// cout << to << endl;
		if (to == -inf) {
			to = ls[f].fin();
		}
		// cout << f << to << endl;
		Tree.set(ls[f].x0, ls[f].x1+1, to);
	}
	int to = Tree.query(xfinal, xfinal+1);
	if (to == -inf) to = xfinal;
	cout << to << endl;
}