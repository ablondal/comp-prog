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
typedef complex<double> cd;

int h[(int)1e5+7];
int DP[(int)1e5+7] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	rep(i,0,n) cin >> h[i];
	rep(i,1,n){
		DP[i] = 2e9;
		rep(j,i-k,i){
			if (j>=0) {
				DP[i] = min(DP[i], DP[j] + abs(h[i]-h[j]));
			}
		}
	}
	cout << DP[n-1] << endl;
}