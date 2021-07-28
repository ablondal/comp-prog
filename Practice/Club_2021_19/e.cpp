#include <cstdio>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
// typedef pair<int, int> pii;
// typedef vector<int> vi;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int c, n;
	scanf(" %d %d", &c, &n);
	int last[100007];
	int a[100007];

	while(c!=0 && n!=0){
		rep(i,0,c+1) last[i] = -1;
		rep(i,0,n){
			scanf("%d", &a[i]);
			a[i] %= c;
			if (a[i]==0) a[i] = c;
		}
		int end, beg;
		int sum = 0;
		last[sum] = -1;
		rep(i,0,n){
			sum = (sum+a[i])%c;
			if (last[sum]==-1) last[sum] = i;
			else{
				end = i;
				beg = last[sum];
				break;
			}
		}
		rep(i, beg+1, end) printf("%d ", i+1);
		printf("%d\n", end+1);

		scanf("%d%d", &c, &n);
	}
}