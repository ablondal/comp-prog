#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(vector<char>& s, int lim=256) {
		int n = sz(s) + 1, k=0, a, b;
		vi x(all(s)+1), y(n), ws(max(n,lim)), rank(n);
		sa=lcp=y, iota(all(sa),0);
		for(int j=0,p=0;p<n;j=max(1,j*2), lim=p){
			p=j,iota(all(y),n-j);
			rep(i,0,n)if(sa[i]>=j) y[p++]=sa[i]-j;
			fill(all(ws),0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i-1];
			for(int i=n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x,y),p=1,x[sa[0]] = 0;
			rep(i,1,n) a=sa[i-1], b=sa[i], x[b] =
				(y[a]==y[b] && y[a+j]==y[b+j]) ? p-1:p++;
		}
		rep(i,1,n) rank[sa[i]]=i;
		for(int i=0,j; i<n-1;lcp[rank[i++]]=k)
			for(k&&k--, j=sa[rank[i]-1]; s[i+k]==s[j+k];k++);
	}
};

// inline int g_p(vi &vs, int n){
// 	for(int i=0; i<sz(vs); ++i){
// 		if (n<vs[i]) return i;
// 	}
// 	return -1;
// }

const int maxN = 1e6+107;

char set_in[maxN];

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);
	vi vs;
	// string c;
	// int i=0;
	vector<char> cc;
	// vector<char> set_in;
	int si = 0;
	int curr_set = 0;
	char ch;

	while(scanf("%c",&ch) != EOF){
		set_in[si++] = (curr_set);
		if(ch=='\n'){
			cc.push_back(26+curr_set);
			curr_set++;
		}else{
			cc.push_back(ch - 'a');
		}
	}

	int sv = (1<<curr_set)-1;

	// for (auto cha : cc) printf("%d", cha);
	// printf("\n");

	if (curr_set==1){
		printf("%d\n", sz(cc)-1);
		return 0;
	}

	// int m = 0;
	// int tm = -1;
	
	int subs = 0;

	SuffixArray arr(cc, 37);

	// stack<int> curr_lngs;

	int lo = 0, hi = 0, md;
	bool tm, w;
	rep(i, 1, sz(arr.lcp)-curr_set){
		hi = max(hi, arr.lcp[i]+1);
	}

	while(hi-lo > 1){
		// printf("%d %d\n", lo, hi);
		md = (hi+lo)/2;
		w = false;
		tm = false;
		rep(i,1,sz(arr.lcp)-curr_set){
			if (arr.lcp[i]>=md){
				if (!tm) subs = (1 << set_in[arr.sa[i-1]]);
				subs |= (1<< set_in[arr.sa[i]]);
				if (subs == sv){
					// printf("%d %d\n", arr.sa[i], subs);
					w = true;
					break;
				}
				tm = true;
			}else{
				tm = false;
			}
		}
		if (w) lo = md;
		else hi = md;
	}

	printf("%d\n", lo);

	// rep(i,1,sz(arr.lcp)-curr_set){
	// 	if (arr.lcp[i]>m){
	// 		int tm = arr.lcp[i];
	// 		// cout << arr.sa[i] << " " << cc.substr(arr.sa[i], arr.lcp[i]) << endl;
	// 		subs = (1 << set_in[arr.sa[i-1]]);
	// 		subs |= (1<< set_in[arr.sa[i]]);
	// 		int j=i+1;
	// 		while(j<sz(arr.lcp)-curr_set && arr.lcp[j]>m && subs != sv ){
	// 			tm = min(tm, arr.lcp[j]);
	// 			subs |= (1<< set_in[arr.sa[j]] );
	// 			j++;
	// 		}
	// 		if (subs==sv) m=tm;
	// 	}
	// }
	// printf("%d\n", m);
}






















