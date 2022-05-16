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
const int MX = 1e5+7;
int DP[MX] = {0};
int H[MX] = {0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> H[i];
		if (i){
			DP[i] = 1e9;
			rep(j,i-2,i){
				if (j>=0) DP[i] = min(DP[i], DP[j]+abs(H[i]-H[j]));
			}
		}
	}
	cout << DP[n-1] << endl;
}