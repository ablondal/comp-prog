
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;

int DP[1007][MAXN] = {{0}};
int P[1007][MAXN] = {{0}};


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, c;
	cin >> n >> c;
	vi obj(n);
	rep(i,0,n) cin >> obj[i];
	sort(all(obj));
	reverse(all(obj));
	rep(i,0,n+1) DP[i][0] = 1;
	// DP[0][0] = 1;
	rep(i,1,n+1){
		int o=obj[i-1];
		rep(j,o,c+1){
			DP[i][j] = DP[i-1][j];
			P[i][j] = P[i-1][j];
			if (DP[i-1][j-o]){
				P[i][j] = i;
				DP[i][j] = DP[i-1][j-o];
			}
			// printf("%d %d: %d %d\n", i, j, DP[i][j], P[i][j]);
		}
	}
	int j;
	for(j=1;j<c;++j){
		// cout << j << endl;
		vi rents;
		int ind = P[n][j];
		int used = j;
		while(ind!=0){
			rents.push_back(obj[ind-1]);
			// cout << rents.back() << " ";
			int nind = P[ind-1][used-obj[ind-1]];
			used -= obj[ind-1];
			ind = nind;
		}
		if (sz(rents)==0) continue;
		// cout << endl << endl;
		if (sz(rents)==n)break;
		rep(i,0,n){
			if (i == sz(rents)){
				if (obj[n-i-1]+j<=c){
					break;
				}else{
					goto out;
				}
			}
			if(rents[i] != obj[n-i-1]){
				if (obj[n-i-1] + j <= c){
					break;
				}else{
					goto out;
				}
			}
		}
		// if (obj[n-sz(rents)-1] + j <= c) break;
	}
	out:
	cout << j << endl;

}