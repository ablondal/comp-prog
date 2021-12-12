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

ll DP[107][100007] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, w;
	cin >> n >> w;
	vector<ll> ws(n), vs(n);
	rep(i,0,n){
		cin >> ws[i] >> vs[i];
	}
	rep(i,0,n){
		rep(W,0,w+1){
			if (ws[i] + W <= w){
				DP[i+1][ws[i]+W] = max(DP[i+1][ws[i]+W], DP[i][W] + vs[i]);
			}
			DP[i+1][W] = max(DP[i+1][W], DP[i][W]);
			DP[i+1][W] = max(DP[i+1][W], DP[i+1][W-1]);
		}
	}
	cout << DP[n][w] << endl;
}