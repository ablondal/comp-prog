#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll Q(ll x, ll y){
	cout << x << " " << y << endl;
	ll r;
	cin >> r;
	return r;
}

int main(){
	cin.tie(0) ->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	bool done = false;
	rep(i,0,n){
		done = false;
		ll xlo = 0, xhi = 1e6, ylo = 0, yhi = 1e6;
		while(xhi-xlo){
			int md = (xhi+xlo)/2;
			ll a = Q(md, 0);
			if (a == 0) {
				done = true;
				break;
			}
			ll b = Q(md+1, 0);
			if (b == 0) {
				done = true;
				break;
			}
			if (b < a){
				xlo = md+1;
			} else {
				xhi = md;
			}
		}
		if (done) continue;
		ll r = Q(xlo, 0);
		r = (ll) (sqrtl(r) + 0.5) ;
		ll r2 = Q(xlo, r);
		assert(r2 == 0);

		// while(yhi-ylo){
		// 	int md = (yhi+ylo)/2;
		// 	ll a = Q(xlo, md);
		// 	if (a == 0) {
		// 		done = true;
		// 		break;
		// 	}
		// 	ll b = Q(xlo, md+1);
		// 	if (b == 0) {
		// 		done = true;
		// 		break;
		// 	}
		// 	if (b < a){
		// 		ylo = md+1;
		// 	} else {
		// 		yhi = md;
		// 	}
		// }
		// if (done) continue;
		// ll r = Q(xlo, ylo);
		// assert(r == 0);
	}
}