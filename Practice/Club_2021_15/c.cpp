#include <bits/stdc++.h>
using namespace std;
// done, love me some np-hard bitmasking
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = (1<<16);

ll d[16][16] = {{0}};
ll DP[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	while(n!=0){
		cin >> m;
		rep(i,0,n) rep(j,0,n){
			d[i][j] = 1e9;
		}
		ll tot = 0;
		vi edg(n, 0);
		rep(i,0,m){
			ll a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			tot += c;
			edg[a]++;
			edg[b]++;
			d[a][b] = min(d[a][b], c);
			d[b][a] = d[a][b];
		}
		for (int k = 0; k < n; ++k) {
		    for (int i = 0; i < n; ++i) {
		        for (int j = 0; j < n; ++j) {
		            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
		        }
		    }
		}

		vi odd;
		rep(i,0,n){
			if (edg[i]%2==1){
				odd.push_back(i);
			}
		}
		int target = 0;
		for(int i : odd) target |= (1<<i);

		rep(i,0,(1<<n)) DP[i] = 1e9;

		DP[0] = 0;

		rep(mask, 0, (1<<n)){
			if ( (mask ^ (mask & target)) != 0 ) continue;
			rep(ai, 0, sz(odd)){
				int a = odd[ai];
				int aa = (1<<a);
				if ( aa & mask ) continue;
				rep(bi, ai+1, sz(odd)){
					int b = odd[bi];
					int bb = (1<<b);
					if ( bb & mask ) continue;
					DP[mask | bb | aa] = min(DP[mask | bb | aa], DP[mask] + d[a][b]);
				}
			}
		}
		cout << DP[target] + tot << endl;
		cin >> n;
	}
}