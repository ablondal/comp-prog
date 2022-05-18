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

double cross(cd a, cd p) { return imag(conj(a)*p); }
double cross(cd p, cd a, cd b) { return cross(a-p, b-p); }

inline pair<double, double> get_ang_dist(cd pos, cd a, cd b){
	cd lnorm = (b-a)*cd(0,1);
	lnorm /= abs(lnorm);
	auto d = lnorm * (real(lnorm * conj(b-pos)));
	// cout << d << endl;
	return {arg(d), abs(d)};
}

cd intersection_pt(pair<double, double> l1, pair<double, double> l2){
	if (l1.first == l2.first) return {-1e18, -1e18};

	double a1 = real(exp(cd(0,1) * l1.first));
	double b1 = imag(exp(cd(0,1) * l1.first));
	double c1 = l1.second;
	double a2 = real(exp(cd(0,1) * l2.first));
	double b2 = imag(exp(cd(0,1) * l2.first));
	double c2 = l2.second;

	double x = - (c1*b2 - c2*b1) / (a1 * b2 - a2 * b1);
	double y = - (a1*c2 - a2*c1) / (a1 * b2 - a2 * b1);
	return {x, y};
}

// Construct line
// (A, B) dot (X-p1, Y-p2) = 0
// AX + BY - Ap1 - Bp2 = 0
// AX + BY - r(A^2 + B^2) = 0
// AX + BY - C = 0

// Take line as defined from normal and dist from 0
cd line2pt(pair<double, double> ang_d){
	return cd(exp(cd(0,1) * ang_d.first) / ang_d.second);
}

// Returns line as Ax + By + C = 0
array<double, 3> pt2line(cd pt){
	return {real(pt), imag(pt), -1};
}

vector<cd> convexHull(vector<cd> pts){
	if (sz(pts) <= 1) return pts;
	sort(all(pts), [](cd a, cd b){return real(a)==real(b) ? imag(a)<imag(b) : real(a)<real(b);});
	vector<cd> h(sz(pts)+1);
	int s = 0, t = 0;
	for (int it = 2; it--; s= --t, reverse(all(pts))) {
		for (auto p : pts) {
			while( t >= s + 2 && cross(h[t-2], h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	}
	return {h.begin(), h.begin() + t - (t==2 && h[0]==h[1])};
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t = 1;
	int N, W, H, x, y, x1, y1, x2, y2;
	while(cin >> N){
		vector<pair<double, double>> ang_dist;
		cin >> W >> H >> x >> y;
		cd p(x,y);
		ang_dist.push_back(get_ang_dist(p, cd(0, 0), cd(0, H)));
		ang_dist.push_back(get_ang_dist(p, cd(0, 0), cd(W, 0)));
		ang_dist.push_back(get_ang_dist(p, cd(0, H), cd(W, H)));
		ang_dist.push_back(get_ang_dist(p, cd(W, 0), cd(W, H)));
		rep(i,0,N){
			cin >> x1 >> y1 >> x2 >> y2;
			ang_dist.push_back(get_ang_dist(p, cd(x1,y1), cd(x2, y2)));
		}

		vector<cd> dualpts;
		for(auto &line : ang_dist){
			dualpts.push_back(line2pt(line));
		}

		// Do convex hull of the dualpts
		auto hull = convexHull(dualpts);
		vector<pair<double, double>> g_lines;
		for(auto pt : hull){
			g_lines.push_back({arg(pt), 1/abs(pt)});
		}

		vector<cd> pts;

		rep(i,0,sz(g_lines)){
			pts.push_back(intersection_pt(g_lines[i], g_lines[(i+1)%sz(g_lines)]));
		}

		// get area
		double area = 0;
		rep(i,0,sz(pts)){
			int j = (i+1)%sz(pts);
			area += ( imag((pts[i]+pts[j])/2.0)*real(pts[i]-pts[j]) );
		}
		printf("Case #%d: %0.3f\n", t, abs(area));

		// cout << setprecision(16) << abs(area) << endl;
		t++;

	}
}
















