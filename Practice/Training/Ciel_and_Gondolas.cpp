#include <bits/stdc++.h>
#include <stdio.h>
// #ifdef WIN32
// // no getchar_unlocked on Windows so call _getchar_nolock
// inline int getchar_unlocked() { return _getchar_nolock(); }
// #endif
 
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 4007;
const int INF = 1e9;
 
int DP[MAXN][MAXN]; // DP[i][x] is the minimum cost to get x people into the first i gondolas
int u[MAXN][MAXN];
int sumu[MAXN][MAXN];
int pen[MAXN][MAXN];
 
inline int penalty(int a, int b){
	// Gets penalty for segment [a, b]
	// = half of the sum of the matrix u from [a, a] to [b, b]
	return (sumu[b][b] + sumu[a-1][a-1] - sumu[b][a-1] - sumu[a-1][b])/2;
}
 
void get_DP(int i, int l, int r, int lptr, int rptr){
	if (l>r) return;
	// printf("%d %d %d %d %d:\n", i, l, r, lptr, rptr);
	int mid = (l+r)>>1;
	ll m = INF;
	int mi = -1;
	rep(j,lptr,min(mid, rptr)+1){
		if (DP[i-1][j] + pen[j+1][mid] < m){
			mi = j;
			m = DP[i-1][j] + pen[j+1][mid];
		}
		// tie(m, mi) = min(tie(m, mi), tie( ((int)DP[i-1][j] + (int)penalty(j+1, mid)) , j));
	}
	DP[i][mid] = m;
	// printf("%d %d: %d\n", i, mid, m);
	get_DP(i, l, mid-1, lptr, mi);
	get_DP(i, mid+1, r, mi, rptr);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	scanf("%d%d\n", &n, &k);
	// char S[MAXN*2];
	// char *b = S;
	// size_t bufsize = MAXN*2;
	rep(i,1,n+1){
		int j = 1;
		while(j<=n){
			char s = getchar();
			if ('0'<=s && s<='9') u[i][j++] = s-'0';
		}
	}
	rep(i,1,n+1) rep(j,1,n+1) sumu[i][j] = sumu[i-1][j] + sumu[i][j-1] - sumu[i-1][j-1] + u[i][j];
	rep(i,1,n+1) rep(j,i,n+1) pen[i][j] = penalty(i,j);
	// DP[0][0] = 0;
	// rep(x,1,n+1) DP[0][x] = INF;
	rep(x,1,n+1) DP[1][x] = pen[1][x];
 
	rep(i,2,k+1){
		get_DP(i, 1, n, 1, n);
	}
	int ans = DP[k][n];
	printf("%d\n", DP[k][n]);
}