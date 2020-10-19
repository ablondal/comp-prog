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

ll sq[107][12] = {{0}};

vi adj[107];

int main() {
	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	rep(i,0,m){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	sq[s][0] = 1;
	rep(i,0,10){
		rep(a,0,n){
			for(auto e: adj[a]){
				sq[e][i+1] += sq[a][i];
			}
		}
	}
	ll tot = 0;
	rep(a,0,n){
		tot += sq[a][t];
	}
	printf("%lli\n", tot);
}