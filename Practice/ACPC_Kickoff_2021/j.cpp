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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("two2.in","r",stdin);
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if (n%2==1){
			cout << -1 << endl;
		} else {
			cout << n/2 << endl;
		}
		// cout << tot << endl;
	}
}