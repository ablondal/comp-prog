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
// https://www-acmicpc-net.translate.goog/problem/19277?_x_tr_sl=auto&_x_tr_tl=en&_x_tr_hl=en-US&_x_tr_pto=nui

struct node{
	int l, r;
	ll x, add_x, set_x;
};
node T[400007];

void makeT(vi& v){
	int n = sz(v);
	rep(i,0,n){
		T[n+i] = {i, i+1, v[i], 0, 0};
	}
	for(int i=n-1;i>0;--i){
		node& a = T[2*i];
		node& b = T[2*i+1];
		T[i] = {a.l, b.r, max(a.x, b.x), 0, 0};
	}
}

void push(int i){
	if (i>=n) break;
	node &a=T[2*i], &b=T[2*i+1];
	a.add_x += T[i].add_x;
	b.add_x += T[i].add_x;
	a.x += T[i].add_x;
	b.x += T[i].add_x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vi v(n);
	rep(i,0,n){
		cin >> v[i];
	}
	makeT(v);

	rep(i,0,q){
		int t, l, r, x;
		cin >> t >> l >> r >> x;
		if (t==0) {
			addT(l, r+1, x);
		} else if (t==1) {
			divT(l, r+1, x);
		} else {
			cout << maxT(l, r+1) << endl;
		}
	}
}