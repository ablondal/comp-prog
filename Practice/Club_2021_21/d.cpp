#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;

struct MaxTree {
	typedef ll T;
	static constexpr T unit = -1e10;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	MaxTree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct MinTree {
	typedef ll T;
	static constexpr T unit = 1e10;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	MinTree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int X[MAXN], Y[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	MaxTree maxUR(n);
	MinTree minUR(n);
	MaxTree maxUL(n);
	MinTree minUL(n);
	rep(i,0,n){
		cin >> X[i] >> Y[i];
		maxUR.update(i, X[i]+Y[i]);
		minUR.update(i, X[i]+Y[i]);
		maxUL.update(i, -X[i]+Y[i]);
		minUL.update(i, -X[i]+Y[i]);
	}
	int q;
	cin >> q;
	rep(i,0,q){
		char x;
		cin >> x;
		if (x=='Q'){
			int l, r;
			cin >> l >> r;
			cout << max(
				abs(maxUR.query(l, r+1) - minUR.query(l, r+1)),
				abs(maxUL.query(l, r+1) - minUL.query(l, r+1))
			) << endl;
		}else{
			int j, x, y;
			cin >> j >> x >> y;
			X[j] = x;
			Y[j] = y;
			maxUR.update(j, X[j]+Y[j]);
			minUR.update(j, X[j]+Y[j]);
			maxUL.update(j, -X[j]+Y[j]);
			minUL.update(j, -X[j]+Y[j]);
		}
	}
}