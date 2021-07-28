#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 2e5+7;

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

vi T[4*MAXN];

void build(vi &a, int v, int tl, int tr) {
    if (tl == tr) {
        T[v] = vector<int>(1, a[tl]);
    } else { 
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        merge(T[v*2].begin(), T[v*2].end(), T[v*2+1].begin(), T[v*2+1].end(),
              back_inserter(T[v]));
    }
}

int n_rep(int v, int tl, int tr, int l, int r, int x){
	if (l>r) return 0;
	if (l==tl && r==tr){
		// cout << lower_bound(all(T[v]), x)-T[v].begin() << endl;
		return lower_bound(all(T[v]), x)-T[v].begin();
	}
	int tm = (tl+tr)/2;
	return n_rep(v*2, tl, tm, l, min(r, tm), x)
			+ n_rep(v*2+1, tm+1, tr, max(l, tm+1), r, x);
}


int rangeComp(const string &s, const string &t, int pos, int len){
	rep(i,0,len){
		if (s[pos+i]<t[i]) return -1;
		else if (s[pos+i]>t[i]) return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	s.push_back('z'+1);
	SuffixArray ar(s);
	build(ar.sa,1,0,sz(s)-1);
	// rep(i,0,sz(ar.sa)){
	// 	cout << ar.sa[i] << " ";
	// }
	// cout << endl;
	int q;
	cin >> q;
	rep(i,0,q){
		string t;
		int k;
		cin >> t >> k;
		int ranglo, ranghi;

		// Search for lower bound of match
		int lo=0, hi=sz(s);
		while(hi-lo>1){
			int md = (hi+lo)>>1;
			if (rangeComp(s, t, ar.sa[md], sz(t)) < 0){
				lo = md;
			}else{
				hi = md;
			}
		}
		ranglo = hi;

		// For upper bound
		lo=0, hi=sz(s);
		while(hi-lo>1){
			int md = (hi+lo)>>1;
			if (rangeComp(s, t, ar.sa[md], sz(t)) <= 0){
				lo = md;
			}else{
				hi = md;
			}
		}
		ranghi = hi;

		// cout << ranglo << " " << ranghi << endl;

		if (ranghi-ranglo < k){
			cout << -1 << endl;
			continue;
		}

		// rep(ii,ranglo, ranghi){
		// 	cout << ar.sa[ii] << " ";
		// }
		// cout << endl;

		// Now we get kth smallest in [ranglo, ranghi)
		lo=0, hi=sz(s);
		while(hi-lo>1){
			int md = (hi+lo)>>1;
			int nr = n_rep(1,0,sz(s)-1,ranglo,ranghi-1,md);
			// cout << t << "," << k << ": " << md << " counts " << nr << endl;
			if (nr <= k-1){
				lo = md;
			}else{
				hi = md;
			}
		}
		cout << hi << endl;
	}
}