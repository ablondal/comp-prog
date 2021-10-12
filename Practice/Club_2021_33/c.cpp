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

ll DP[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vi h(n);
	rep(i,0,n) cin >> h[i];
	DP[0] = 0;
	rep(i,1,n){
		DP[i] = 1e18;
		rep(j, max(0,i-k), i){
			DP[i] = min(DP[i], DP[j] + abs(h[j]-h[i]));
		}
	}
	cout << DP[n-1] << endl;
}