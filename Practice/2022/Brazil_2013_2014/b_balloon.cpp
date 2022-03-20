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
typedef vector<vll> mat;
const ll MAX = 507;

set<vi> V;

int curr_x;

struct l_s{
	int xs,ys,dx,dy,i;
	inline float yatx(int x){
		return ys + dy*((x-xs)/(float)dx);
	}
	bool operator<(l_s& b){
		return tie(xs, ys) < tie(b.xs, b.ys);
	}
};

struct le{
	bool operator()(l_s a, l_s b)const{
		return a.yatx(curr_x) < b.yatx(curr_x);
	}
};

set<l_s, le> OS;
vi adj[100007];

pair<int, int> tr[4000007];
void make(int v, int l, int r){
	if (r-l==1) tr[v] = {l, -1};
	else {
		int md = (l+r)/2;
		make(2*v,l,md);
		make(2*v+1,md,r);
		tr[v] = {-1, -1};
	}
}
pair<int, int> get(int v, int l, int r, int t_l){
	if (tr[v] != make_pair(-1, -1)){
		return tr[v];
	} else {
		int md = (l+r)/2;
		return (md <= t_l ? get(2*v+1, md, r, t_l) : get(2*v, l, md, t_l));
	}
}
void sset(int v, int l, int r, int t_l, int t_r, pair<int,int> x){
	if (t_l <= l && r <= t_r){
		tr[v] = x;
	} else if (t_l >= r || t_r <= l){
		return;
	} else {
		int md = (l+r)/2;
		if (tr[v] != make_pair(-1, -1)) tr[2*v] = tr[2*v+1] = tr[v];
		tr[v] = {-1, -1};
		sset(2*v, l, md, t_l, t_r, x);
		sset(2*v+1, md, r, t_l, t_r, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, C;
	cin >> N >> C;
	vector<l_s> segs(1);
	vector<pair<int, int>> se;
	rep(i,1,N+1){
		l_s A;
		cin >> A.xs >> A.ys >> A.dx >> A.dy;
		if (A.xs > A.dx){
			swap(A.xs, A.dx);
			swap(A.ys, A.dy);
		} else if (A.xs == A.dx){
			continue;
		}
		segs.push_back(A);
		segs.back().i = sz(segs)-1;
		se.push_back({segs.back().xs, i});
		se.push_back({segs.back().dx, -i});
		segs.back().dx -= segs.back().xs;
		segs.back().dy -= segs.back().ys;
	}
	N = sz(segs)-1;
	sort(all(se));
	rep(i,0,sz(se)){
		auto [x,ind] = se[i];
		curr_x = x;
		if (ind > 0){
			auto [it,v] = OS.insert(segs[ind]);
			if (it != OS.begin()){
				it--;
				adj[ind].push_back(it->i);
				it++;
			}
			it++;
			if (it != OS.end()){
				adj[it->i].push_back(ind);
			}
		} else {
			OS.erase(OS.find(segs[-1*ind]));
		}
	}

	// Topo sort
	queue<int> rdy;
	vi left(N+1,0);
	rep(i,1,N+1){
		for(auto& e:adj[i]){
			left[e]++;
		}
	}
	rep(i,1,N+1){
		if (left[i]==0) rdy.push(i);
	}
	make(1, 0, (int)1e6+1);
	while(!rdy.empty()){
		int i = rdy.front();
		auto& c = segs[i];
		rdy.pop();
		// cout << i << endl;
		pair<int, int> res;
		if (c.dy == 0){
			res = {-2, c.ys};
		} else if (c.dy > 0){
			res = get(1, 0, (int)1e6+1, c.xs+c.dx);
			if (res.first == -2) {
				res.first = c.xs + c.dx;
			}
		} else {
			res = get(1, 0, (int)1e6+1, c.xs);
			if (res.first == -2) {
				res.first = c.xs;
			}
		}

		sset(1, 0, (int)1e6+1, c.xs, c.xs+c.dx+1, res);

		for(auto& e : adj[i]){
			left[e]--;
			if (left[e]==0) rdy.push(e);
		}
	}

	rep(i,0,C){
		int x;
		cin >> x;
		auto [u, v] = get(1, 0, (int)1e6+1, x);
		if (u == -2) u = x;
		if (v == -1) {
			cout << u << endl;
		} else {
			cout << u << " " << v << endl;
		}
	}
}