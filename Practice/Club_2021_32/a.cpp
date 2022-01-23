#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5+7;

ll DP[MX];
ll h[MX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> h[i];
	}
	DP[0] = 0;
	DP[1] = abs(h[1]-h[0]);
	rep(i,2,n){
		DP[i] = min(
			DP[i-1] + abs(h[i-1]-h[i]),
			DP[i-2] + abs(h[i-2]-h[i])
		);
	}
	cout << DP[n-1] << endl;
}