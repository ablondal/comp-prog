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
	double x,y,z;
	pt operator+(pt b){return {x+b.x, y+b.y, z+b.z};}
	pt operator-(pt b){return {x-b.x, y-b.y, z-b.z};}
	pt operator*(double c){return {c*x, c*y, c*z};}
	double abs2(){return (x*x + y*y + z*z);}
	double abs(){return sqrt(abs2());}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pt> pts(n+1);
	rep(i,0,n+1){
		cin >> pts[i].x >> pts[i].y >> pts[i].z;
	}
	int vp, vs;
	pt P;
	cin >> vp >> vs;
	cin >> P.x >> P.y >> P.z;

	double t = 0;
	bool fd = false;
	rep(i,0,n){
		// Will HP catch on this segment?
		double next_d = (pts[i+1]-P).abs();
		double next_t = t + (pts[i+1]-pts[i]).abs()/vs;
		double nt = (pts[i+1]-pts[i]).abs()/vs;
		if ( next_d / vp <= next_t ){
			fd = true;
			cout << "YES" << setprecision(12) << endl;
			// Will catch!
			double hi = 1, lo = 0;
			int ct = 0;
			while(hi-lo > 1e-13){
				ct++;
				double md = (hi+lo)/2;
				pt a = pts[i] + ((pts[i+1]-pts[i])*md);
				if ( (a-P).abs() / vp > t + (nt*md) ){
					lo = md;
				} else {
					hi = md;
				}
			}
			pt a = pts[i] + ((pts[i+1]-pts[i])*lo);
			cout << (a-P).abs() / vp << endl;
			cout << a.x << " " << a.y << " " << a.z << endl;
			break;
		}
		t = next_t;
	}

	if (!fd){
		cout << "NO" << endl;
	}

}