#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll INF = 1e18+1;

typedef struct{
    ll dist = INF;
    int re = 0;
} dist;

dist d[107][107];

typedef struct{
    int u,v;
    ll c;
} weight;

weight w[10007];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, k, m;
        cin >> n >> k >> m;

        rep(i,0,m) cin >> w[i].u >> w[i].v >> w[i].c;

        ll lo = 0, hi = 1e18;
        while(hi-lo > 1){
            rep(i,0,n) rep(j,0,n) d[i][j].dist = INF, d[i][j].re = INF;
            
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (d[i][k] < INF && d[k][j] < INF)
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
                    }
                }
            }
        }
	}
}