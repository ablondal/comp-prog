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

ll ax, ay, bx, by, tx, ty;
ll x, y;
int n, q;
int F[(int)1e5+7] = {0};
int S[(int)1e5+7] = {0};

int main() {
	scanf("%d %d", &n, &q);
	rep(i,0,n) scanf("%d", F+i);
	S[0] = F[0];
	rep(i,1,n) S[i] = F[i] ^ S[i-1];
	S[n] = 0;
	rep(i,0,q){
		int k;
		scanf("%d", &k);
		k %= (n+1);
		printf("%d\n", S[k-1]);
	}

}























