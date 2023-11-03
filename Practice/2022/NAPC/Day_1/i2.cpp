#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5+7;

struct TNode {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); }
	vector<T> s; int n;
	TNode(int n = 0, T def = unit) : s(2*n, def), n(n) {} 
	void update(int pos, T val){
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos*2], s[pos*2+1]);
	}
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for(b += n, e += n; b < e; b /= 2, e /=2) {
			if (b%2) ra = f(ra, s[b++]);
			if (e%2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
	T query(int b) {
		int a = (b+n)/2;
		vi ps;
		for(; a > 0; a /= 2){
			ps.push_back(a);
		}
		reverse(all(ps));
		for(int i : ps){
			if (s[i] != unit) {
				s[2*i] = s[2*i+1] = s[i];
				s[i] = unit;
			}
		}
		return s[a+n];
	}
	void set(int b, int e, T x) {
		for(b += n, e += n; b < e; b /= 2, e /=2) {
			if (b%2) s[b++] = x;
			if (e%2) s[--e] = x;
		}
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
	TNode Tree(2000007);
	const int offset = 1000003;
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
		int to = Tree.query(ls[f].fin()+offset);
		cout << to << endl;
		if (to == TNode::unit) {
			to = ls[f].fin();
		}
		cout << f << to << endl;
		Tree.set(ls[f].x0+offset, ls[f].x1+1+offset, to);
	}
	int to = Tree.query(xfinal+offset);
	if (to == TNode::unit) to = xfinal;
	cout << to << endl;
}