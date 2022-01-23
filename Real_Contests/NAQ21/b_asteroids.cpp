#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct pt3{
	double x, y, z;
};

pt3 operator*(double a, pt3 b){
	return {a*b.x, a*b.y, a*b.z};
}

pt3 operator+(pt3 a, pt3 b){
	return {a.x+b.x, a.y+b.y, a.z+b.z};
}

pt3 operator-(pt3 a, pt3 b){
	return {a.x-b.x, a.y-b.y, a.z-b.z};
}

double dist2(pt3 a, pt3 b){
	auto c = a-b;
	return c.x*c.x + c.y*c.y + c.z*c.z;
}

double dot(pt3 a, pt3 b){
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

double fulldist(pt3 p, pt3 apos, pt3 adir){
	double tmp1 = dot(apos-p, adir);
	double s = tmp1 / dot(adir, adir);
	s = max(s, 0.0);
	pt3 np = apos + s*adir;
	return dist2(p, np);
}

double fulld2(pt3 p, pt3 apos, pt3 adir){
	double lo = 0, hi = 1e7;
	while(hi-lo > 1e-7){
		double m1 = lo + (hi-lo)/3.0;
		double m2 = lo + 2.0*(hi-lo)/3.0;
		double d1 = dist2(p, apos + m1*adir);
		double d2 = dist2(p, apos + m2*adir);
		if (d1 < d2) {
			hi = m2;
		} else {
			lo = m1;
		}
	}
	return dist2(p, apos + lo*adir);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pt3 ship, base;
	cin >> ship.x >> ship.y >> ship.z >> base.x >> base.y >> base.z;
	int n;
	cin >> n;
	bool good = true;
	rep(i,0,n){
		pt3 pos, dir;
		int m;
		cin >> pos.x >> pos.y >> pos.z >> dir.x >> dir.y >> dir.z >> m;
		double rad2 = 0;
		rep(j,0,m){
			pt3 out;
			cin >> out.x >> out.y >> out.z;
			rad2 = max(rad2, dist2(pos, out));
		}
		// cout << rad2 << endl;
		double lo = 0, hi = 1, mdist = 1e18;
		while(hi-lo > 1e-7){
			double m1 = lo + (hi-lo)/3.0;
			double m2 = lo + 2.0*(hi-lo)/3.0;
			pt3 p1 = ship + m1*(base-ship);
			pt3 p2 = ship + m2*(base-ship);
			// cout << p1.x << " " << p1.y << " " << p1.z << endl;
			double d1 = fulld2(p1, pos, dir);
			double d2 = fulld2(p2, pos, dir);
			// cout << hi << " " << lo << " " << d1 << " " << d2 << endl;

			mdist = min(mdist, min(d1, d2));
			if (d1 < d2) {
				hi = m2;
			} else {
				lo = m1;
			}
		}
		// cout << mdist << endl;
		if (mdist < rad2) {
			good = false;
		}
	}
	cout << (good ? "Go" : "Surrender") << endl;


}