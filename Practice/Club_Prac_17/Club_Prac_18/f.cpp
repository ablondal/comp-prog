#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int k;
	scanf(" %d", &k);
	while(k){
		int n, m;
		scanf(" %d %d", &n, &m);
		rep(i,0,k){
			int x, y;
			scanf(" %d %d", &x, &y);
			if (x==n || y==m){
				printf("divisa\n");
			}else if(x < n && y < m){
				printf("SO\n");
			}else if(x>n && y<m){
				printf("SE\n");
			}else if(x>n && y>m){
				printf("NE\n");
			}else if(x<n && y>m){
				printf("NO\n");
			}
		}
		scanf(" %d", &k);
	}
}