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
	int k;
	// priority_queue<int, vi, greater<int>> Q;
	// int tot = 0;
	cin >> k;
	rep(i,0,k){
		// Q.clear();
		// tot = 0;
		ll n,x,t;
		cin >> n >> x >> t;
		ll overlap = t / x;
		overlap = min(overlap, n-1);
		ll ans = overlap * n - (overlap+1)*(overlap)/2LL;
		cout << ans << endl;
	}
}