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

int a[103];
int p[101];

int t;
int main(){
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d%d", &n, &m);
		rep(i,1,n+1) scanf("%d", a+i);
		rep(i,0,m) scanf("%d", p+i);
		rep(i,0,n+1){
			rep(j,0,m){
				int k = p[j];
				if (a[k] > a[k+1]){
					int tmp = a[k+1];
					a[k+1] = a[k];
					a[k] = tmp;
				}
			}
		}
		bool isSort = true;
		rep(i,1,n){
			if (a[i]>a[i+1]) isSort = false;
		}
		printf(isSort ? "YES\n" : "NO\n");
	}
}
























