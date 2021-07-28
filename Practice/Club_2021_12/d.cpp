#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef struct{
	int w, s, v;
} block;

ll DP[1003][20004] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	scanf("%d", &n);
	vector<block> a(n);
	rep(i,0,n){
		scanf("%d%d%d", &a[i].w, &a[i].s, &a[i].v);
	}
	sort(all(a), [](block aa, block b){return aa.s+aa.w > b.s+b.w;});
	// set<pair<int, ll> > vals;
	// set<pair<int, ll> > vals2;
	// vals.insert({1e8, 0});
	rep(i,0,n){
		rep(j,0,2e4+1){
			DP[i+1][j] = max(DP[i+1][j], DP[i][j]);
			int mcap = min(j - a[i].w, a[i].s);
			if (i==0) mcap = a[i].s;
			if (mcap>=0)
				DP[i+1][mcap] = max(DP[i+1][mcap], DP[i][j]+a[i].v);
		}
	}
	ll mm = 0;
	rep(j,0,1e4+1){
		mm = max(mm, DP[n][j]);
	}
	printf("%lld\n", mm );
}