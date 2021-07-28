#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int w[507];
	int b[1007];
	rep(i,1,n+1){
		cin >> w[i];
		// cout << w[i] << endl;
	}
	ll tot = 0;
	rep(i,0,m){
		cin >> b[i];
		vi vis(n+1,0);
		ll cu = 0;
		for(int j=i-1; j>=0 && b[j] != b[i]; --j){
			// cu += w[b[j]];
			vis[b[j]] = 1;
		}
		rep(j,0,n+1){
			// cout << vis[j]*w[j] << endl;
			cu += vis[j]*w[j];
		}
		// cout << cu << endl << endl;
		tot += cu;
	}
	cout << tot << endl;

}