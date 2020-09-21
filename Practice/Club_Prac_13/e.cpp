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

int fol[100007] = {0};

int leng[100007] = {0};

int m_l(int i){
	// printf("%d", i);
	if (i == 0 || i == -1){
		return 0;
	}
	return leng[i] = m_l(fol[i])+1;
}

int n, m;
int c, l;
int main(){
	scanf("%d%d", &n, &m);
	rep(i, 0, m){
		scanf("%d", &l);
		rep(j, 1, n){
			scanf("%d", &c);
			if (fol[l]==0) fol[l] = c;
			else if (fol[l] != c) fol[l] = -1;
			l = c;
		}
		fol[l] = -1;
	}
	ll tot = 0;
	// printf("%lli\n", tot);
	rep(i, 1, n+1){
		if (leng[i]){
			tot += leng[i];
		}else{
			tot += m_l(i);
		}
	}
	printf("%lli\n", tot);
}
























