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
	double x1, x2, y1, y2;
	double vx1, vx2, vy1, vy2;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> vx1 >> vy1 >> vx2 >> vy2;
	double dist;
	if (vx1 == vx2 && vy1 == vy2){
		dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	} else {
		double dvx = vx1 - vx2;
		double dvy = vy1 - vy2;
		double t = -( (x1-x2)*dvx + (y1-y2)*dvy) / ( (vx1-vx2)*(vx1-vx2) + (vy1-vy2)*(vy1-vy2) );
		if (t <= 0){
			dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		} else {
			x1 += t*vx1;
			x2 += t*vx2;
			y1 += t*vy1;
			y2 += t*vy2;
			dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		}
	}
	cout << setprecision(18) << dist << endl;

}