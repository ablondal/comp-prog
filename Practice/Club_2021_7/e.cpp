#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll INF = 1e17+1;

ll DP[(int)1e5+7][2] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> f(n), b(n);
	vector<ll> c(n);
	rep(i,0,n) cin >> c[i];
	rep(i,0,n){
		cin >> f[i];
		b[i] = f[i];
		reverse(all(b[i]));
	}
	DP[0][0] = 0;
	DP[0][1] = c[0];
	rep(i,1,n){
		DP[i][0] = DP[i][1] = INF;
		if (f[i]>=b[i-1]) DP[i][0] = min(DP[i][0], DP[i-1][1]);

		if (f[i]>=f[i-1]) DP[i][0] = min(DP[i][0], DP[i-1][0]);

		if (b[i]>=b[i-1]) DP[i][1] = min(DP[i][1], DP[i-1][1] + c[i]);

		if (b[i]>=f[i-1]) DP[i][1] = min(DP[i][1], DP[i-1][0] + c[i]);
	}
	if (min(DP[n-1][0], DP[n-1][1]) == INF) cout << -1 << endl;
	else cout << min(DP[n-1][0], DP[n-1][1]) << endl;
}