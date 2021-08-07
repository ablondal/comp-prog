#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	vi a(t);
	rep(i,0,t) cin >> a[i];
	vi DP(t+2, 1e9+7);
	DP[0] = 0;
	rep(i,0,t){
		DP[i+1] = min(DP[i+1], DP[i]+abs(a[i]-a[i+1]));
		DP[i+2] = min(DP[i+2], DP[i]+abs(a[i]-a[i+2]));
	}
	cout << DP[t-1] << endl;
	
}