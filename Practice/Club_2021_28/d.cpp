#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int dx, dy, n, q;
	int cc = 0;
	scanf("%d%d%d%d", &dx, &dy, &n, &q);
	// cin >> dx >> dy >> n >> q;
	while(dx != 0){
		// if (dx==0) break;
		cc++;

		vector<vi> summ(2007, vi(2007,0));

		vi x(n), y(n);
		rep(i,0,n){
			scanf("%d%d", &x[i], &y[i]);
			summ[ x[i]+y[i] ][ x[i]-y[i]+1001 ] = 1;
		}
		rep(yy,1,2007) rep(xx, 1, 2007){
			summ[xx][yy] += summ[xx-1][yy] + summ[xx][yy-1] - summ[xx-1][yy-1];
		}

		printf("Case %d:\n", cc);

		

		while(q--){
			int m;
			int ans = 0;
			int xi = 1, yi = 1;
			scanf("%d", &m);

			rep(yy, 1, dy+1){
				rep(xx,1,dx+1){
					int xpos = xx+yy;
					int ypos = xx-yy+1001;
					int top = min(ypos+m, 2006);
					int right = min(xpos+m, 2006);
					int bot = max(ypos-m, 1);
					int left = max(xpos-m, 1);

					int num = summ[right][top] + summ[left-1][bot-1] - summ[right][bot-1] - summ[left-1][top];
					if (num > ans) {
						xi = xx;
						yi = yy;
						ans = num;
					}
				}
			}
			printf("%d (%d,%d)\n", ans, xi, yi);
		}
		scanf("%d%d%d%d", &dx, &dy, &n, &q);
	}
}