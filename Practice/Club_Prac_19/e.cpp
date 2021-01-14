#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <queue>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map <int, int> from_l;
vi is, js;

ll compare(int l, int r){
	if (r==l+1) return 0;
	int m = (l+r)/2;
	ll tot = compare(l,m) + compare(m, r);
	// printf("pls\n");
	priority_queue <int> Qi(is.begin()+l, is.begin()+m);
	priority_queue <int> Qj(js.begin()+m, js.begin()+r);
	while(!Qi.empty()){
		while(!Qj.empty() && Qj.top()>=Qi.top()){
			Qj.pop();
		}
		// printf("%d\n", sz(Qj));
		tot+= sz(Qj);
		Qi.pop();
	}
	return tot;
}

int main() {
	int t;
	scanf("%d", &t);
	vi a(t);
	is.resize(t);
	js.resize(t);
	rep(k,0,t){
		scanf("%d", &a[k]);
		if (from_l.find(a[k]) == from_l.end()) from_l[a[k]]=0;
		is[k] = ++from_l[a[k]];
	}
	for(int k=t-1; k>=0; --k){
		js[k] = from_l[a[k]] - is[k] + 1;
	}
	// printf("hi\n");
	printf("%lli\n", compare(0, t));

}