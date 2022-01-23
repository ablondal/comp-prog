#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x, y, x2, y2;
	cin >> x >> y;
	cin >> x2 >> y2;

	int n;
	cin >> n;
	
	int ct = 0;
	rep(i,0,n){
		ll a, b, c;
		cin >> a >> b >> c;
		int me = (a*x + b*y + c) > 0;
		int they = (a*x2 + b*y2 + c) > 0;
		if (me != they){
			ct++;
		}
	}
	cout << ct << endl;
}