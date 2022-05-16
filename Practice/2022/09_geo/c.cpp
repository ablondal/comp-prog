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
typedef complex<ll> ci;
const double PI = acos(-1);

double calcdist(vector<cd>& pts){
	double d = 0;
	rep(i,1,sz(pts)){
		d += abs(pts[i]-pts[i-1]);
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	vector<cd> pts;
	vector<double> times;
	rep(i,0,n){
		int x, y, z;
		cin >> x >> y >> z;
		pts.emplace_back(x,y);
		times.emplace_back(z);
	}
	double totd = calcdist(pts);

	vector<cd> gpts;
	gpts.emplace_back(pts[0]);
	int ctime = t;
	int i = 0;
	while(ctime < times.back()){
		while(times[i] < ctime) i++;
		gpts.emplace_back(
			pts[i-1] + 
			(pts[i]-pts[i-1]) *
				(	((double)ctime - times[i-1])
					/
					(times[i]-times[i-1])
				)
		);

		ctime += t;
	}
	gpts.emplace_back(pts.back());

	double gptime = calcdist(gpts);

	cout << setprecision(18) << 100 * (1 - (gptime / totd)) << endl;
}