#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll DP[3007][3007] = {{0}}; // position and largest value used
const ll mod = 1e9+7;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	DP[0][0] = 1;
	rep(i,1,n){
		// i is length considered
		if (s[i-1] == '<'){
			ll sum = 0;
			for(int j=1; j<i+1; ++j){
				sum += DP[i-1][j-1];
				sum %= mod;
				DP[i][j] = sum;
			}
		}else{ // > 
			ll sum = 0;
			for(int j = i-1; j>=0; --j){
				sum += DP[i-1][j];
				sum %= mod;
				DP[i][j] = sum;
			}
		}
		// rep(j,0,i+1){
		// 	printf("%d %d: %lld\n", i, j, DP[i][j]);
		// }
	}
	ll tot = 0;
	rep(j,0,n){
		tot += DP[n-1][j];
		tot %= mod;
	}
	cout << tot << endl;
}