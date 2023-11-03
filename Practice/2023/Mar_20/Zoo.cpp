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

struct pt{
	ll x, y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	vector<pt> pts(m);
	rep(i,0,m){
		cin >> pts[i].x >> pts[i].y;
	}
	sort(all(pts), [](pt a, pt b){return a.y < b.y;});
	// rep(i,0,m){
	// 	cout << pts[i].x << " " << pts[i].y << endl;
	// }
	vector<int> binos(n+1, 1);
	rep(i,0,m){
		auto& p1 = pts[i];
		rep(j,i+1,m){
			auto& p2 = pts[j];
			ll dx = p2.x - p1.x;
			ll dy = p2.y - p1.y;
			if (dx == 0 && p2.x <= n){
				int ct = 2;
				rep(k,j+1,m){
					if (pts[k].x == p2.x){
						ct++;
					}
				}
				binos[p2.x] = max(binos[p2.x], ct);
			} else if (dy == 0){
				continue;
			}else if ( (p2.y * dx) % dy == 0 ) {
				ll nx = (p2.x - (p2.y * dx)/dy);
				if (nx < 1 || nx > n) continue;

				ll g = gcd(p2.x - nx, p2.y);
				ll nnx = (p2.x - nx)/g;
				ll nny = (p2.y)/g;

				int ct = 2;
				rep(k,j+1,m){
					auto& p3 = pts[k];
					ll g2 = gcd(p3.x - nx, p3.y);
					ll nnx2 = (p3.x - nx)/g2;
					ll nny2 = (p3.y)/g2;
					if (nnx2 == nnx && nny2 == nny){
						ct++;
						// cout << k << " " << j << " " << i << endl;
						// cout << nnx2 << " " << nnx << " " << nny2 << " " << nny << endl;
					}
				}
				binos[nx] = max(binos[nx], ct);
			}
		}
	}
	ll tot = 0;
	rep(i,1,n+1){
		tot += binos[i];
		// cout << binos[i] << endl;
	}
	cout << tot << endl;
}