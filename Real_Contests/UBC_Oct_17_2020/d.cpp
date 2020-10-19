#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

long long DP[807][807] = {{0}};
long long DPn[807][807] = {{0}};

int main() {
	int t;
	scanf("%d", &t);
	DP[402][402] = 1;
	// ll tot = 0;
	while(t--){
		rep(i,0,807) rep(j,0,807) DPn[i][j] = DP[i][j];
		int x, y;
		scanf("%d%d", &x, &y);
		rep(i,0,807){
			rep(j,0,807){
				if (0<= i+x && i+x<807 && 0<=j+y && j+y<807){
					DPn[i+x][j+y] += DP[i][j];
				}
			}
		}
		// tot += DPn[402][402];
		swap(DP, DPn);
	}
	printf("%lli\n", DP[402][402]-1);
}