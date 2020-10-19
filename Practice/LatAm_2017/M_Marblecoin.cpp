#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 399;

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(vector<int> &s, int lim = 400){
		int n = sz(s) + 1, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for(int j=0, p=0; p<n; j = max(1, j*2), lim=p) {
			p = j, iota(all(y), n-j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i-1];
			for(int i=n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p=1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i-1], b = sa[i], x[b] =
				(y[a]==y[b] && y[a+j] == y[b+j]) ? p-1 : p++;
		}
		// rep(i,1,n) rank[sa[i]] = i;
		// for(int i=0, j; i<n-1; lcp[rank[i++]] = k){
		// 	for(k && k--, j=sa[rank[i]-1];
		// 		s[i+k] == s[j+k]; k++);
		// }
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<int> stack;
	vi f(n);
	vi rank;
	int totn = 0;
	rep(i,0,n){
		int k, t;
		scanf("%d", &k);
		totn += k;
		f[i] = sz(stack);
		rep(j,0,k) scanf("%d", &t), stack.push_back(t);
		stack.push_back(INF);
	}
	SuffixArray SA(stack);

	rank.resize(sz(stack)+1,-1);
	rep(i,0,sz(SA.sa)) rank[SA.sa[i]] = i;

	// rep(i,0,sz(rank)) printf("%d\n", rank[i]);

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int> > > Q;

	rep(i,0,n) Q.push({rank[f[i]],f[i]});

	ll tot = 0;
	ll M = 1e9+7;
	rep(j,0,totn){
		tot *= 365;
		tot %= M;
		int i = Q.top().second;
		Q.pop();
		tot += 365 * stack[i];
		tot %= M;
		Q.push({rank[i+1], i+1});
	}
	printf("%lli\n", tot);
}




















