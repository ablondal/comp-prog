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
const double eps = 1e-7;

pair<cd, double> ternsearch(cd dir, cd t1, double r){
	double lo = 0, hi = r;
	while(hi-lo > eps){
		auto md1 = lo + 1.0*(hi-lo)/3.0;
		auto md2 = lo + 2.0*(hi-lo)/3.0;
		auto r1 = min(r-md1, abs(md1*dir - t1));
		auto r2 = min(r-md2, abs(md2*dir - t1));
		// auto rl = min(r-lo, abs(lo*dir - t1));
		// auto rh = min(r-hi, abs(hi*dir - t1));

		if (r1 > r2) {
			hi = md2;
		} else {
			lo = md1;
		}
		cout << lo << " " << hi << endl;
	}
	return {lo, min(r-lo, abs(lo*dir - t1))};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double r, x1,x2,y1,y2;
	cin>>r>>x1>>y1>>x2>>y2;
	cd t1(x1,y1), t2(x2,y2);
	cd dir = t1-t2;
	dir /= abs(dir);
	dir *= 1if;
	auto [a1, r1] = ternsearch(dir, t1, r);
	dir *= -1;
	auto [a2, r2] = ternsearch(dir, t2, r);
	if (r1 > r2) {
		cout << setprecision(12) << r1 << endl;
		cout << a1.real() << " " << a1.imag() << endl;
	} else {
		cout << setprecision(12) << r2 << endl;
		cout << a2.real() << " " << a2.imag() << endl;
	}

}