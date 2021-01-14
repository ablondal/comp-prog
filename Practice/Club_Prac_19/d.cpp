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

int nxt[1000007] = {0};

int cnt[1000007] = {0};
int a, b;

int q[1000007] = {0};

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		nxt[a] = b;
		cnt[a]--;
		cnt[b]++;
	}
	int cur = nxt[0];
	int i=1;
	while(cur){
		q[i] = cur;
		cur = nxt[cur];
		i+=2;
	}
	int j=0;
	for(;j<1000007;++j){
		if(cnt[j]==-1){
			break;
		}
	}
	cur = j;
	i = 0;
	while(cur){
		q[i] = cur;
		cur = nxt[cur];
		i+=2;
	}
	i=0;
	while(q[i]){
		printf("%d",q[i]);
		if (q[i+1]) printf(" ");
		i++;
	}
	printf("\n");
}




