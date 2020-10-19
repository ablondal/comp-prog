#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi adj[307];
int sx[307];
int sy[307];
int sz[307];
int L[307], R[307];
char V[307];

bool DFS(int v){
	if (R[v]) return true;
	if (V[v]) return false;
	V[v] = true;
	for(auto e: adj[v]){
		if(DFS(e)){
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	int k = -1;
	rep(i,0,t){
		// int x, y, z;
		memset(V, 0, 307);
		scanf("%d%d%d", sx+i, sy+i, sz+i);
		if(k!=-1) continue;
		if ( sz[i] > 200-sx[i] ) R[i] = true;
		if ( sz[i] > sx[i] ) L[i]=true;
		// printf("%d %d\n", L[i], R[i]);
		rep(j,0,i){
			if ((sx[i]-sx[j])*(sx[i]-sx[j]) + (sy[i]-sy[j])*(sy[i]-sy[j]) <= (sz[i]+sz[j])*(sz[i]+sz[j])){
				adj[i].push_back(j);
				adj[j].push_back(i);
				// printf("%d %d\n", j, i);
			}
		}
		bool g = 0;
		rep(j,0,i+1){
			if (!L[j] || V[j]) continue;
			if (DFS(j)){
				g = true;
				break;
			}
		}
		if (g) k=i;
	}
	printf("%d\n", k);
}