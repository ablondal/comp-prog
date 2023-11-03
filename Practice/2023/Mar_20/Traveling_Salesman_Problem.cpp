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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int my = 0, My = 0, mx = 0, Mx = 0;
		rep(i,0,n){
			int x, y;
			cin >> x >> y;
			my = min(my, y);
			My = max(My, y);
			mx = min(mx, x);
			Mx = max(Mx, x);
		}
		int tot = Mx * 2 + (-2 * mx) + My * 2 + (-2 * my);
		cout << tot << endl;
	}
}