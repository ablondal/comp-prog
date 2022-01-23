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
const double PI = acos(-1);

pair<double, double> closestpt(cd p1, cd p2){
	cd tmp = (p1) / (p2-p1);
	return {abs(tmp.imag()), -tmp.real()};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cd P;
	double x, y;
	cin >> n >> x >> y;
	P = {x,y};
	vector<cd> pgon(n);
	rep(i,0,n){
		cin >> x >> y;
		pgon[i] = {x,y};
		pgon[i] -= P;
	}
	double m = 1e9;
	double M = -1e9;
	rep(i,0,n){
		m = min(m, abs(pgon[i]));
		M = max(M, abs(pgon[i]));
	}
	rep(i,0,n){
		auto pt1 = pgon[i], pt2 = pgon[(i+1)%n];
		auto [a, t] = closestpt(pt1, pt2);
		// cout << a << " " << t << " " << a*abs(pt2-pt1) << endl;
		if (0 <= t && t <= 1) {
			m = min(m, a*abs(pt2-pt1));
		}
	}
	// cout << m << " " << M << endl;
	cout << setprecision(15) << PI * M * M - PI * m * m << endl;
}