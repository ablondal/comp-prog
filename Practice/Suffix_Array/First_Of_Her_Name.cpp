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

const int MAXN = 1e6 + 7;
const int MAXL = 23;

char c[MAXN], q[MAXN];
int p[MAXN] = {0};
int pz[MAXN][MAXL] = {{0}};
int rk[MAXN][MAXL] = {{0}};
int n, k, ci, pi;

int main(){
	c[0] = 'A'-1;
	scanf("%d%d", &n, &k);
	rep(i,1,n+1){
		scanf(" %c %d", c+i, p+i);
		pz[i][0] = p[i];
	}
	vi sa(n+1,0), ws(27,0), pos(n+1,0);
	rep(i,0,n+1) sa[i] = i;
	rep(i,1,n+1) ws[c[i]-'A'+1]++;
	rep(i,1,27) ws[i]+=ws[i-1];
	for(int i=n; i>0; --i) rk[i][0] = ws[c[i]-'A'+1];

	for(int j = 0, nn=0; nn <= n; nn = max(1, nn*2), ++j){
		rep(i,1,n+1) pz[i][j+1] = pz[pz[i][j]][j];

		sort(all(sa), [&j](int a, int b){
			return make_pair(rk[a][j], rk[pz[a][j]][j]) < make_pair(rk[b][j], rk[pz[b][j]][j]);
		});
		rk[sa[0]][j+1] = 0;
		rep(i,1,n+1){
			int a = sa[i], b = sa[i-1];
			if (make_pair(rk[a][j], rk[pz[a][j]][j]) == make_pair(rk[b][j], rk[pz[b][j]][j])){
				rk[sa[i]][j+1] = rk[sa[i-1]][j+1];
			}else{
				rk[sa[i]][j+1] = i;
			}
		}
	}

	// rep(i,0,n+1){
	// 	int a = sa[i];
	// 	printf("%d ", sa[i]);
	// 	while(a){
	// 		printf("%c", c[a]);
	// 		a = pz[a][0];
	// 	}
	// 	printf("\n");
	// }

	rep(j,0,k){
		scanf(" %s", q);
		int lo1=0, hi1=n+1, lo2=0, hi2=n+1, md1, md2, i;
		while(lo1!=hi1-1 || lo2!=hi2-1){
			md1 = (lo1+hi1) / 2;
			md2 = (lo2+hi2) / 2;
			int a = sa[md1];
			for(i=0; q[i] && q[i]==c[a]; a = pz[a][0],++i);
			if (!q[i]){
				lo1 = md1;
			}else if(q[i]>c[a]){
				lo1 = md1;
			}else{
				hi1 = md1;
			}
			a = sa[md2];
			for(i=0; q[i] && q[i]==c[a]; a = pz[a][0],++i);
			if (!q[i]){
				hi2 = md2;
			}else if(q[i]>c[a]){
				lo2 = md2;
			}else{
				hi2 = md2;
			}
		}
		
		// for(i=hi2; i<hi1; ++i){
		// 	int a = sa[i];
		// 	while(a){
		// 		printf("%c", c[a]);
		// 		a = pz[a][0];
		// 	}
		// 	printf("\n");
		// }
		// printf("%d %d\n", hi1, hi2);
		printf("%d\n", hi1-hi2);
	}
}














