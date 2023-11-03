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
typedef long double ld;
const ld eps = 1e-9;

// If balloon is at (a, b, c)

// (x + t*dx - a)**2 + (y + t*dy - b)**2 + (z + t*dz - c)**2 <= r**2
// Minimum of that value is at
// 2 * dx * (x + t*dx - a) + ... = 0
// t(2dx^2 + 2dy^2 + 2dz^2) = 2dx(a-x) + 2dy(b-y) + 2dz(c-z)
// t = (dx(a-x) + dy(b-y) + dz(c-z))/(dx^2 + dy^2 + dz^2)
struct v3{
	ld x,y,z;
	v3 operator+(v3 a){return {x+a.x, y+a.y, z+a.z};}
	v3 operator-(v3 a){return {x-a.x, y-a.y, z-a.z};}
	v3 operator*(ld c){return {c*x, c*y, c*z};}
	ld dot(v3 a){return x*a.x + y*a.y + z*a.z;}
	ld operator*(v3 a){return dot(a);}
	ld r2(){return dot(*this);}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	while(n != 0){
		vector<v3> b(n);
		vector<ld> r(n);
		vector<bool> hit(n, false);
		rep(i,0,n){
			cin >> r[i] >> b[i].z >> b[i].x >> b[i].y; 
			b[i].z += r[i];
		}
		int m; cin >> m;
		rep(i,0,m){
			int ct = 0;
			v3 p, d;
			cin >> p.x >> p.y >> p.z >> d.x >> d.y >> d.z;
			d = d*(1 / sqrt(d.r2()));
			// cout << "Shot: " << p.x << " " << p.y << " " << p.z << " in dir ";
			// cout << d.x << " " << d.y << " " << d.z << endl;
			rep(j,0,n){
				if (hit[j]) continue;
				auto a = b[j];
				ld t = d*(a-p);
				if (t < 0) continue;
				// cout << "B: (" << a.x << " " << a.y << " " << a.z << ") at time ";
				// cout << t << ": ";
				// cout << min((p-a+(d*t)).r2(), (p-a).r2()) << endl;
				if ((p-a+(d*t)).r2() < (r[j]*r[j])+eps){
					ct++;
					hit[j] = true;
				}
			}
			cout << ct << endl;
		}
		cin >> n;
	}
}