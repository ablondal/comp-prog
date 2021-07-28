#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9+7;
unordered_map<ll, int> M;

int v[107];
int w[107];

ll DP[107][100007];

int get_val(int i, int cap){
	if (cap < 0) return -INF;
	if (i==-1) return 0;
	ll h = ((ll)i*1e10 + cap);
	if (M.count(h)){
		return M[h];
	}
	return M[h] = max(v[i] + get_val(i-1, cap-w[i]), get_val(i-1, cap));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	rep(i,0,107) rep(j,0,100007) DP[i][j] = INF;

	int N, W;
	scanf("%d%d", &N, &W);
	rep(i,0,N){
		scanf("%d%d", w+i, v+i);
	}
	DP[0][v[0]] = w[0];
	DP[0][0] = 0;
	rep(i,1,N){
		rep(j,0,v[i]){
			DP[i][j] = DP[i-1][j];
		}
		rep(j,v[i],100007){
			DP[i][j] = min(DP[i-1][j], DP[i-1][j-v[i]]+w[i]);
		}
	}
	int m = 0;
	rep(j,0,100007){
		// printf("%d %d: %d\n", N-1, j, DP[N-1][j]);

		if (DP[N-1][j] <= W){
			m = j;
		}
	}
	printf("%d\n", m);
}