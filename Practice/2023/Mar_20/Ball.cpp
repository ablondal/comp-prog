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
	double a, b, m;
	double vx, vy, vz;
	cin >> a >> b >> m >> vx >> vy >> vz;
	vy = abs(vy);

	int negx = vx < 0;
	int negz = vz < 0;
	vx = abs(vx);
	vz = abs(vz);

	double fx = (a/2) + (vx * m/vy);
	double fz = (vz * m/vy);

	// cout << fx << " " << fx

	int nx = floor(fx / a);
	int nz = floor(fz / b);
	if (nx % 2 == negx){
		fx = fx - a * nx;
	} else {
		fx = a - (fx - a*nx);
	}
	if (nz % 2 == negz){
		fz = fz - b * nz;
	} else {
		fz = b - (fz - b*nz);
	}
	cout << setprecision(10) << fx << " " << fz << endl;
}