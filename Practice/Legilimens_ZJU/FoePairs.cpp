#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define min(a,b) ((a<b)?a:b)
typedef pair <int, int> pii;
const int MAXN = 300007;
int pos[MAXN];
int per[MAXN];
int last[MAXN] = {0};

int main(){
	int n, m, a, b, t, pa, pb;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i){
		scanf("%d", &t);
		pos[t] = i;
		last[i] = n+1;
	}
	for(int j=0; j<m; ++j){
		scanf("%d%d", &a, &b);
		pa = pos[a];
		pb = pos[b];
		if (pb < pa){
			pa = pb;
			pb = pos[a];
		}
		last[pa] = min(last[pa], pb);
	}
	priority_queue <pii, vector<pii>, greater<pii> > Q;
	long long totn = 0;
	int end = 1;
	Q.push({last[1], 1});
	for(int beg = 1; beg<=n; ++beg){
		// printf("Last of %d is %d\n", beg, last[beg]);
		while(!Q.empty() && Q.top().second < beg){
			Q.pop();
			// printf("%d\n", Q.top().first);
		}
		while(end < Q.top().first){
			end++;
			if (end <= n) Q.push({last[end], end});
		}
		// printf("%d %d\n", beg, end);
		totn += (end-beg);
	}
	printf("%lli\n", totn);
}