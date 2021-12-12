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
const int MAXN = 3e5+7;
const ll inf = 1e17;

struct node{
	int l, r;
	ll mx;
	ll add;
};

node T[5*MAXN];

void build(int n){
	int k = 1;
	while(k<n) k<<=1;
	n = k;
	rep(i,n,2*n){
		T[i] = {i-n, i-n+1, -inf, 0};
	}
	for(int i=n-1; i>0; --i){
		auto& c1 = T[2*i];
		auto& c2 = T[2*i+1];
		T[i] = {c1.l, c2.r, max(c1.mx, c2.mx), 0};
	}
	// rep(i,1,2*n){
	// 	cout << "T[" << i << "]: " << T[i].l << " " << T[i].r << endl;
	// }
}

ll getmax(){
	return T[1].mx;
}

void push(int i){
	// cout << "pushing " << i << endl;
	if (T[i].r-T[i].l > 1 && T[i].add != 0){
		T[2*i].add += T[i].add;
		T[2*i].mx += T[i].add;
		T[2*i+1].add += T[i].add;
		T[2*i+1].mx += T[i].add;
		T[i].add = 0;
	} else {
		T[i].add = 0;
	}
}

void add_range(int i, int l, int r, ll x){
	if (T[i].l >= l && T[i].r <= r) {
		T[i].add += x;
		T[i].mx += x;
	} else if (T[i].l >= r || T[i].r <= l){
		return;
	} else {
		push(i);
		add_range(2*i, l, r, x);
		add_range(2*i+1, l, r, x);
		T[i].mx = max(T[2*i].mx, T[2*i+1].mx);
	}
}

void set_val(int i, int pos, ll x){
	if (T[i].l == pos && T[i].r == pos+1){
		T[i].mx = x;
		T[i].add = 0;
	} else if (T[i].l <= pos && pos < T[i].r) {
		push(i);
		set_val(2*i, pos, x);
		set_val(2*i+1, pos, x);
		T[i].mx = max(T[2*i].mx, T[2*i+1].mx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> upds(n+2);
	build(n+2);
	set_val(1,0,0);
	rep(i,0,m){
		int l, r;
		ll a;
		cin >> l >> r >> a;
		upds[l].push_back({l,a});
		upds[r+1].push_back({l,-a});
	}
	ll M = 0;
	rep(i,1,n+1){
		for(auto [pos, x]:upds[i]){
			// cout << i << ": " << pos << " " << x << endl;
			add_range(1, 0, pos, x);
		}
		ll val = getmax();
		M = max(M, val);
		set_val(1, i, val);
		// cout << i << " " << val << endl;
	}
	cout << M << endl;
}