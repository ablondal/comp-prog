#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// https://github.com/kth-competitive-programming/kactl/blob/main/content/strings/SuffixArray.h
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
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		// ASCII of | is greater than 'Z', so end-of-word is
		// sorted after. E.G. "abca" < "abc", since "abca|" < "abc|".
		string c = a+"|"+b+"|";
		SuffixArray SA(c);

		// SA.sa is a list of indices in order.
		// We get the order of each index in order to properly compare them.
		vi posc(sz(c)+1);
		rep(i,0,sz(SA.sa)){
			posc[SA.sa[i]] = i;
		}

		string ans = "";
		int i=0, j=0;
		// Add one letter to ans at a time.
		while(i < sz(a) || j < sz(b)){
			// Compare the suffix of string a to the suffix of string b
			// Index math cause of '|' below
			if (posc[i] < posc[sz(a)+1+j]){
				ans.push_back(a[i++]);
			}else{
				ans.push_back(b[j++]);
			}
		}
		cout << ans << endl;
	}
}