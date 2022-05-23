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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string s, t;
	rep(i,0,m){
		cin >> t;
		for(auto c : t){
			s.push_back(c);
		}
		s.push_back('Z'+1);
	}
	s.push_back('Z'+2);
	// cout << s << endl;
	map<int, int> Map;
	int bad = 0;
	SuffixArray sa(s);
	vi rev(sz(sa.sa));
	rep(i,0,sz(sa.sa)){
		rev[sa.sa[i]] = i;
	}

	rep(i,0,sz(sa.sa)){
		// cout << sa.sa[i] << " " << sa.lcp[i] << endl;
	}

	rep(i,0,n){
		int M = 1;
		int m = 1e9;
		int p = rev[i];
		int j = p-1;
		while(j!=-1 && sa.sa[j]<n){
			m = min(m, sa.lcp[j+1]);
			j--;
		}
		M = max(M, min(m+1, sa.lcp[j+1]+1) );
		j = p+1;
		m = 1e9;
		while(j < sz(sa.sa) && sa.sa[j]<n){
			m = min(m, sa.lcp[j]);
			j++;
		}
		M = max(M, min(m+1, sa.lcp[j]+1));
		// cout << i << " " << M << endl;
		if (M + i > n+1) bad++;
		else Map[M]++;
	}

	// cout << bad << endl;
	int ct = 0;
	auto it = Map.begin();
	int res = 0;
	while(ct*2 < n && it != Map.end()){
		ct += it->second;
		res = it->first;
		it++;
	}
	if (ct*2 < n) {
		cout << -1 << endl;
	} else {
		cout << res << endl;
	}

}