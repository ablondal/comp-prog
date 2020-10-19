#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, P;
int a[1007], p[1007], v[1007];

int albv[1007] = {0};
int b[1007];

int main() {
	scanf("%d %d %d", &n, &m, &P);
	vector<vi> songs(m+1);
	rep(i,0,n){
		scanf("%d %d %d", a+i, p+i, v+i);
		albv[a[i]] += v[i];
		songs[a[i]].push_back(i);
	}
	rep(i,0,m){
		scanf("%d", b+i+1);
	}

	int DP[1007][2] = {{0}};
	for(int alb=1; alb <= m; ++alb){
		for(int i=0; i+b[alb]<=P; ++i){
			DP[i+b[alb]][1] = max(DP[i+b[alb]][0], DP[i][0]+albv[alb]);
		}
		for(auto s: songs[alb]){
			for(int j=P; j-p[s]>=0; --j){
				DP[j][0] = max(DP[j][0], DP[j-p[s]][0]+v[s]);
			}
		}
		rep(i,0,P+1){
			DP[i][0] = max(DP[i][0], DP[i][1]);
			// printf("%d ", DP[i][0]);
		}
		// printf("\n");
	}
	int MM = 0;
	rep(i,0,P+1) MM = max(MM, DP[i][0]);

	printf("%d\n", MM);


}























