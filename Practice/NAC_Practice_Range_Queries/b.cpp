#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;
int siz;

int tab[18][MAXN][16] = {{0}};
int LOG[MAXN];

void poptable(vector<vi>& orig, int n){
	for(int i=0; i<n; ++i){
		for(int k=0; k<siz; ++k){
			tab[0][i][k] = orig[i][k];
		}
	}
	for(int j=1; j<=LOG[n]; ++j){
		for(int i=0; i + (1<<j) <= n; ++i){
			for(int k=0; k<siz; ++k){
				tab[j][i][k] = max(tab[j-1][i][k], tab[j-1][i+(1<<(j-1))][k]);
			}
		}
	}
}

vector<int> query(int l, int r){
	vi a(siz,-1e9);
	int j = LOG[r-l+1];
	for(int k=0; k<siz; ++k){
		a[k] = max(tab[j][l][k], tab[j][r-(1<<j)+1][k]);
	}
	return a;
}

struct Tree {
	typedef vi T;
	T unit;
	inline void f(T& a, T& b, T& c) {
		// vi c(siz);
		rep(i,0,siz){
			// if (i%2) c[i] = min(a[i], b[i]);
			// else c[i] = max(a[i], b[i]);
			c[i] = max(a[i],b[i]);
		}
		// return c;
	} // (any associative fn)
	vector<T> s; int n;
	Tree(int n, vector<vi>& orig) : s(2*n, vi(siz)), n(n) {
		unit.resize(siz);
		rep(i,0,siz){
			// if (i%2) unit[i] = 1e9;
			// else unit[i] = -1e9;
			unit[i] = -1e9;
		}
		rep(i,n,2*n){
			s[i] = orig[i-n];
		}
		// cout << "ok" << endl;
		for (int i=n-1; i>0; --i){
			f(s[i*2], s[i*2+1], s[i]);
		}
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			f(s[pos * 2], s[pos * 2 + 1], s[pos]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) f(ra, s[b++], ra);
			if (e % 2) f(s[--e], rb, rb);
		}
		f(ra, rb, ra);
		return ra;
	}
};

inline ll res(int l, int r, int klo, int khi) {
	ll oop = -abs(khi - klo);
	ll tot = oop;
	auto b = query(l, r);
	// auto b = vi(siz, 0);
	for(int i=0; i<siz/2; ++i){
		tot = max(tot, oop + abs(b[2*i]+b[2*i+1]));
	}
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	LOG[1] = 0;
	rep(i,2,MAXN) LOG[i] = 1+LOG[i/2];

	int n, k;
	scanf("%d %d", &n, &k);
	// cin >> n >> k;
	siz = 1;
	rep(i,1,k) siz *= 2;
	vi C(k);
	rep(i,0,k) scanf("%d", &C[i]);
	vector<vi> orig(n, vi(siz,0));
	vector<vi> KK(n, vi(k,0));
	rep(i,0,n){
		// vi K(k);
		rep(j,0,k){
			scanf("%d", &KK[i][j]);
			// cin >> KK[i][j];
			KK[i][j] *= C[j];
		}
	}
	sort(all(KK), [&k](vi& a, vi& b){return a[k-1] < b[k-1];});
	cout << "1" << endl;
	rep(i,0,n){
		auto& K = KK[i];
		rep(j,0,siz){
			int j2 = j/2;
			orig[i][j] += K[0];
			rep(l,1,k-1){
				if (j2 & (1<<(l-1))){
					orig[i][j] += K[l];
				} else {
					orig[i][j] -= K[l];
				}
			}
			if (j & 1) orig[i][j] *= -1;
		}
		// cout << i << " ";
		// rep(j,0,siz) cout << orig[i][j] << " ";
		// cout << endl;
	}
	cout << "2" << endl;
	// Tree a(n, orig);
	poptable(orig, n);
	ll M = 0;

	// cout << "hi" << endl;
	cout << "3" << endl;
	rep(i,1,n){
		int lo = 0, hi = i;
		while(hi-lo>2){
			int md1 = lo + (hi-lo)/3;
			int md2 = lo + 2*(hi-lo)/3;
			auto r1 = res(md1, i, KK[md1-1][k-1], KK[i][k-1]);
			auto r2 = res(md2, i, KK[md2-1][k-1], KK[i][k-1]);
			M = max(M, r1);
			M = max(M, r2);
			if (r1 > r2){
				hi = md2;
			} else {
				lo = md1+1;
			}
		}
		M = max(M, res(lo, i, KK[lo][k-1], KK[i][k-1]));
		M = max(M, res(lo+1, i, KK[lo+1][k-1], KK[i][k-1]));
	}
	printf("%lld\n", M);
	// cout << M << endl;
}