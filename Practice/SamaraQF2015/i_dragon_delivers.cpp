#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MX = 1e3+7;
ll DP[MX] = {0};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,d,c;
	cin >> n>>d>>c;
	vi t(n+1);
	rep(i,1,n+1) cin >> t[i];
	t[0] = t[1];
	
	DP[0] = 0;
	// DP[1] = d;
	rep(i,1,n+1){
		ll totdaycost = 0;
		DP[i] = 2e18;
		for(int j=i-1; j>=0; j--){
			totdaycost += c * (t[i]-t[j+1]);
			DP[i] = min(DP[i], DP[j]+totdaycost+d);
		}
		// cout << DP[i] << endl;
	}
	cout << DP[n] << endl;
}