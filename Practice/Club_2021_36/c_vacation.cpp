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

int DP[100007][3] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		int a, b, c;
		cin >> a >> b >> c;
		DP[i+1][0] = a + max(DP[i][1], DP[i][2]);
		DP[i+1][1] = b + max(DP[i][0], DP[i][2]);
		DP[i+1][2] = c + max(DP[i][0], DP[i][1]);
	}
	cout << max(max(DP[n][0], DP[n][1]), DP[n][2]) << endl;
	
}