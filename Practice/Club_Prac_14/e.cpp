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

int n, m, t, N, M;
int main(){
	scanf(" %d %d", &N, &M);
	while(N!=0 && M!=0){
		int ans;
		if (N>M){
			n = M;
			m = N;
		}else{
			n = N;
			m = M;
		}
		if (n==1){
			ans = m;
		}else if (n==2){
			if (m%4 == 0){
				ans = m;
			}else if (m%4 == 1){
				ans = m + 1;
			}else if (m%4 == 2){
				ans = m + 2;
			}else{
				ans = m + 1;
			}
		}else{
			if (n%2==0 || m%2==0){
				ans = (n*m)/2;
			}else{
				ans = (n*m)/2 + 1;
			}
		}
		printf("%d knights may be placed on a %d row %d column board.\n", ans, N, M);
		scanf(" %d %d", &N, &M);
	}
}
// 4 knights may be placed on a 2 row 3 column board.
// 4 knights may be placed on a 2 row 3 column board.
























