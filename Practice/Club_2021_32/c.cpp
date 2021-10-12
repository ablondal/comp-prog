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
	ll n;
	cin >> n;
	n++;
	ll a=2, b=3, c=5, d=7;
	ll aa=1, bb=1, cc=1, dd=1;
	while(n){
		if (n & 1){
			aa = (a*aa)%17;
			bb = (b*bb)%17;
			cc = (c*cc)%17;
			dd = (d*dd)%17;
		}
		a = (a*a)%17;
		b = (b*b)%17;
		c = (c*c)%17;
		d = (d*d)%17;
		n /= 2;
	}
	cout << (aa+bb+cc+dd)%17 << endl;
}