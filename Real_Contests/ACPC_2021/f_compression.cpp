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

/* public codebook: */
/* https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/SegmentTree.h */
struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c;
	cin >> n >> c;
	vi m1(n), m2(n);
	int last = 0;
	int mxj = 0;
	rep(i,0,n){
		int a;
		cin >> a;
		int b = a;
		m1[i] = 0;
		while(b){
			m1[i]++;
			b /= 2;
		}
		m2[i] = 1;
		b = (a - last);
		if (b == 0){
			m2[i] = 0;
		} else {
			if (b<0) {
				b = abs(b);
				b = b-1;
			}
			while(b){
				m2[i]++;
				b /= 2;
			}
		}
		
		last = a;
		mxj = max(mxj, max(m1[i], m2[i]));
		// cout << m1[i] << "\t\t" << m2[i] << endl;
	}
	// Tree m2s(n), m1s(n);
	// rep(i,0,n){
	// 	m2s.update(i, m2[i]);
	// 	m1s.update(i, m1[i]);
	// }

	// vi laststops(65, -1);
	// laststops[0] = 0;

	vector<vector<ll>> Cs(n+1, vector<ll>(64, 1e18));
	rep(i,0,64) Cs[0][i] = c;

	rep(i,1,n+1){
		rep(j,0,64){
			if (j / 32 == 0 && m1[i-1] > j%32){
				// cout << j << " " << m1[i-1] << endl;
				continue;
			}
			if (j / 32 == 1 && m2[i-1] > j%32){
				// cout << j << " " << m1[i-1] << endl;
				continue;
			}
			rep(k,0,64){
				if (j==k){
					Cs[i][j] = min(Cs[i][j], Cs[i-1][k] + (j % 32));
				} else {
					Cs[i][j] = min(Cs[i][j], Cs[i-1][k] + c + (j%32)); 
				}
			}
		}
		// ll M = 1e18;
		// rep(j,0,64){
		// 	M = min(M, Cs[i][j]);
		// }
		// cout << M << endl;
	}

	ll M = 1e18;
	rep(i,0,64){
		M = min(M, Cs[n][i]);
	}
	cout << M << endl;


	// rep(i,1,n+1){
	// 	Cs[i] = 1e18;
	// 	int s = -1;
	// 	for(int j=0; j<=65; ++j){
	// 		for (int mode = 0; mode<2; ++mode){
	// 			if (laststops[j] != -1) {
	// 				cout << i << " " << laststops[j] << endl;
	// 				int k = laststops[j];
	// 				int ms = (mode == 0) ? m1s.query(k,i) : m2s.query(k,i);
	// 				if (Cs[k] + c + (i-k)*ms < Cs[i]){
	// 					Cs[i] = Cs[k] + c + (i-k)*ms;
	// 					s = mode*32 + ms;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	cout << Cs[i] << endl;
	// 	laststops[s] = i;
	// }

	// rep(i,1,n+1){
	// 	Cs[i] = 1e18;
	// 	rep(j,0,i){
	// 		int ms = min(m1s.query(j,i), m2s.query(j,i));
	// 		Cs[i] = min(Cs[i], c + Cs[j] + (i-j)*ms);
	// 	}
	// 	// cout << Cs[i] << endl;
	// }

	// rep(i,1,n+1){
	// 	Cs[i] = 1e18;
	// 	for(int j = 0; j<=mxj; ++j){
	// 		int lo = -1; int hi = i-1;
	// 		while(hi-lo>1){
	// 			int md = (hi+lo)/2;
	// 			int q = min(m2s.query(md, i), m1s.query(md, i));
	// 			if (q > j){
	// 				lo = md;
	// 			} else {
	// 				hi = md;
	// 			}
	// 		}
	// 		Cs[i] = min(Cs[i], Cs[hi] + (i-hi)*j + c);
	// 	}
	// 	cout << i << " " << Cs[i] << endl;
	// }
	// cout << Cs[n] << endl;
}