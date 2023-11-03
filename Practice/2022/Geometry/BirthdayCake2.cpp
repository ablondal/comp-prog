#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// ax + by + c = dx + ey + f = 0
// ax = -by -c
// x = -b/a y - c/a
// -bd/a y - cd/a + ey + f = 0
// (e - bd/a) y = cd/a - f
// y = (cd / a - f) / (e - bd / a)
// y = (cd - af) / (ea - bd)
// x = (ce - bf) / (ea - bd)

int sgn(double x) { return (x > 0) - (x < 0); }

int main(){
	cin.tie(0) ->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, m, r;
	cin >> n >> m >> r;
	vi xs(n), ys(n);
	rep(i,0,n) cin >> xs[i] >> ys[i];
	vi a(m), b(m), c(m);
	int isecpts = 0;
	rep(i,0,m){
		cin >> a[i] >> b[i] >> c[i];
		rep(j,0,i){
			if (b[j]*a[i] != b[i]*a[j]) {
				double x = ((double)c[i]*b[j] - b[i]*c[j]) / (b[j]*a[i] - b[i]*a[j]);
				double y = ((double)c[i]*a[j] - a[i]*c[j]) / (b[j]*a[i] - b[i]*a[j]);
				if (x*x + y*y < r*r) {
					isecpts++;
				}
			}
		}
	}
	int faces = 1 + m + isecpts;
	if (faces != n) {
		cout << "no" << endl;
		exit(0);
	}
	set<vi> cds;
	rep(i,0,n){
		vi A;
		rep(j,0,m){
			A.push_back(sgn(a[j]*xs[i] + b[j]*ys[i] + c[j]));
		}
		if (cds.count(A)) {
			cout << "no" << endl;
			exit(0);
		}
		cds.insert(A);
	}
	cout << "yes" << endl;

}