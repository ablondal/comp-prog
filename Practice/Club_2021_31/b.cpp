#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[30007] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;

	cin >> n >> t;
	DP[0] = 1;
	rep(i,0,n-1){
		// cout << i << " " << DP[i] << endl;
		int a;
		cin >> a;
		if (DP[i]) DP[i+a] = 1;
	}
	cout << (DP[t-1] ? "YES" : "NO") << endl;
}