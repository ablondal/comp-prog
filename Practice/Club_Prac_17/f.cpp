#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);
	vi a(t);
	rep(i,0,t){
		scanf("%d", &a[i]);
	} 
	sort(all(a));
	vi b(t);
	rep(i,0,t){
		b[i] = (i % 2 == 0) ? a[i/2] : a[(t+1)/2 + i/2];
	}
	rep(i,0,t){
		if (i) printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");
}