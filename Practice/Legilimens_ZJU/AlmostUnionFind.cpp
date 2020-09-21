#include <cstdio>
using namespace std;
const int MAXN = 2e5+7;
long long sum[MAXN] = {0};
int num[MAXN] = {0};
int DUM[MAXN] = {0};
int st[MAXN] = {0};
int n, m;

int find(int n){
	return DUM[n] = (n == DUM[n] ? n : find(DUM[n]) );
}

int main(){
	while(scanf("%d%d", &n, &m) != EOF){
		int i = n+1;
		for(int j=1; j<=n; ++j){
			DUM[j] = j;
			num[j] = 1;
			sum[j] = j;
			st[j] = j;
		}
		int t, a, b, fa, fb;
		for(int j=0; j<m; ++j){
			scanf("%d%d", &t, &a);
			if (t == 1){
				scanf("%d", &b);
				st[a] = fa = find(st[a]);
				st[b] = fb = find(st[b]);
				if (fa != fb){
					DUM[fa] = fb;
					sum[fb] += sum[fa];
					num[fb] += num[fa];
				}
			}else if (t == 2){
				scanf("%d", &b);
				fa = find(st[a]);
				st[b] = fb = find(st[b]);
				if (fa != fb){
					sum[fa] -= a;
					sum[fb] += a;
					num[fa] --;
					num[fb] ++;
					DUM[i] = fb;
					st[a] = i++;
				}
			}else{
				st[a] = fa = find(st[a]);
				printf("%d %lli\n", num[fa], sum[fa]);
			}
		}
	}
}