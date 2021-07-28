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
	ll x, y, xx, yy, n;
	cin >> x >> y >> xx >> yy >> n;
	xx -= x;
	yy -= y;
	x = 0;
	y = 0;
	string a;
	cin >> a;
	vector<pair<ll, ll>> disp(sz(a)+1);
	disp[0] = {0, 0};
	rep(i,0,sz(a)){
		disp[i+1] = disp[i];
		if (a[i] == 'U'){
			disp[i+1].second++;
		}else if (a[i]=='D'){
			disp[i+1].second--;
		}else if (a[i]=='L'){
			disp[i+1].first--;
		}else if (a[i]=='R'){
			disp[i+1].first++;
		}
	}
	ll hi = 1e17;
	ll lo = -1;
	while(hi-lo>1){
		ll md = (hi+lo)>>1;
		ll x = (md / n) * disp[n].first + disp[md % n].first;
		ll y = (md / n) * disp[n].second + disp[md % n].second;
		ll disp = abs(x-xx) + abs(y-yy);
		if (disp <= md){
			hi = md;
		}else{
			lo = md;
		}
	}
	cout << (hi == 1e17 ? -1 : hi) << endl;
}