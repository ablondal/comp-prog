#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi a(n);
		rep(i,0,n) cin >> a[i];
		int m = 1e8;
		rep(i,0,n-1) m = min(m, a[i]);
		int M = 0;
		rep(i,1,n) M = max(m, a[i]);
		if (a[n-1] < m || a[0] > M) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}