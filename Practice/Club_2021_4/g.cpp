#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int n, k, a, b;
	scanf("%d%d%d%d", &n, &k, &a, &b);
	char T[n+1];
	T[n] = 0;
	int last = (a>b) ? 1 : 0;
	int num = k;
	rep(i,0,n){
		if (num==k) {
			last = last ? 0 : 1;
			T[i] = last ? 'B' : 'G';
			if (last) b--;
			else a--;
			num = 1;
		}else if (a>b){
			if (last == 1){
				last = 0;
				T[i] = 'G';
				a--;
				num = 1;
			}else{
				num++;
				T[i] = 'G';
				a--;
			}
		}else{
			if (last == 0){
				last = 1;
				T[i] = 'B';
				b--;
				num = 1;
			}else{
				num++;
				T[i] = 'B';
				b--;
			}
		}
	}
	if (a==0 && b==0){
		printf("%s\n", T);
	}else{
		printf("NO\n");
		// printf("%s\n", T);
	}
}