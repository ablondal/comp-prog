#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
	int n;
	scanf("%d", &n);
	vector <vi> lists(1);
	set<int> S;
	rep(i,1,n+1){
		int t;
		scanf("%d", &t);
		S.insert(t);
		lists.emplace_back(all(S));
	}
	int q;
	scanf("%d", &q);
	int last_ans = 0;
	rep(m,0,q){
		int a,b,c;
		scanf("%d%d%d", &a,&b,&c);
		int i=max(a^last_ans, 1);
		int j=min(b^last_ans, n);
		int k=c^last_ans;
		if (i>j){
			printf("0\n");
			last_ans = 0;
		}

		int lo=-1, hi=j;
		while(hi-lo>1){
			int mid = (lo+hi)/2;
			if(lists[j][mid]<=k){
				lo=mid;
			}else{
				hi=mid;
			}
		}
		// printf("%d\n", hi);
		int greatertop = j-hi;

		lo=-1, hi=i-1;
		while(hi-lo>1){
			int mid = (lo+hi)/2;
			if(lists[i-1][mid]<=k){
				lo=mid;
			}else{
				hi=mid;
			}
		}
		// printf("%d\n", hi);
		int greaterbot = (i-1-hi);
		// printf("%d %d\n", greatertop, greaterbot);
		printf("%d\n", greatertop-greaterbot);
		last_ans = greatertop-greaterbot;
	}
}