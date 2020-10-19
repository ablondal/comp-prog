#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, t;
int tmp;
char op;

vi adj[10];

ll DFS_add(int c, int tot, vi & ms){
	if (tot>=t || (t-tot > (m-c)*n)) return 0;
	// printf("in %d at %d \n", c, tot);
	if (c==m-1 && t-tot <=n){
		if (ms[c] & (1 << (t-tot))) {
			// printf("yes %d %d\n", c, t-tot);
			return 1;
		}else{
			return 0;
		}
	}
	ll ans = 0;
	for(int i=1; i<=n; ++i){
		if (ms[c] & (1 << i)){
			for(auto e: adj[c]){
				ms[e] ^= (1 << i);
			}
			ans += DFS_add(c+1, tot+i, ms);
			for(auto e: adj[c]){
				ms[e] ^= (1 << i);
			}
		}
	}
	// printf("out %d\n", c);
	return ans;
}

ll DFS_mult(int c, ll tot, vi & ms){
	if (tot>t || t % tot != 0) return 0;
	// printf("in %d at %lli \n", c, tot);
	if (c==m-1 && t/tot <= n){
		if (ms[c] & (1 << (t/tot))) {
			// printf("yes %d %lli\n", c, t/tot);
			return 1;
		}else{
			return 0;
		}
	}
	ll ans = 0;
	for(int i=1; i<=n; ++i){
		if (t % (tot*i) != 0) continue;
		if (ms[c] & (1 << i)){
			// vi nms(ms);
			for(auto e: adj[c]){
				ms[e] ^= (1 << i);
			}
			ans += DFS_mult(c+1, tot*i, ms);
			for(auto e: adj[c]){
				ms[e] ^= (1 << i);
			}
		}
	}
	// printf("out %d\n", c);
	return ans;
}

int main() {
	scanf("%d %d %d %c", &n, &m, &t, &op);
	if (op=='-'){
		scanf("%d %d %d %d", &tmp, &tmp, &tmp, &tmp);
		int ans = 0;
		rep(i,1,n+1){
			rep(j,1,i){
				if (abs(i-j)==t){
					ans++;
				}
			}
		}
		printf("%d\n", 2 * ans);
	}else if (op=='/'){
		scanf("%d %d %d %d", &tmp, &tmp, &tmp, &tmp);
		int ans = 0;
		rep(i,1,n+1){
			rep(j,1,i){
				if ( (i%j==0 && i/j == t) ){
					ans++;
				}
			}
		}
		printf("%d\n", 2 * ans);
	}else if (op=='+'){
		vector<pii> sqs(m);
		rep(i,0,m){
			scanf("%d %d", &sqs[i].first, &sqs[i].second);
			rep(j,0,i){
				if (sqs[i].first==sqs[j].first || sqs[i].second == sqs[j].second){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		vi ms(m, (1<<n)-1);
		printf("%lli\n", DFS_add(0, 0, ms));

	}else if (op=='*'){
		vector<pii> sqs(m);
		rep(i,0,m){
			scanf("%d %d", &sqs[i].first, &sqs[i].second);
			rep(j,0,i){
				if (sqs[i].first==sqs[j].first || sqs[i].second == sqs[j].second){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		vi ms(m, (1<<n)-1);
		printf("%lli\n", DFS_mult(0, 1, ms));

	}
}




















