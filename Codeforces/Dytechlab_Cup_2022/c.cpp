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

struct pz{
	int x, y;
	bool const operator<(struct pz b){
		return tie(x, y) < tie(b.x, b.y);
	}
	bool operator==(struct pz b){
		return tie(x, y) == tie(b.x, b.y);
	}
	pz(int a, int b):x(a), y(b){}
	pz():x(0), y(0){}
};

bool check(vector<pz> a, int xr, int yr, int n){
	// Is it stuck in a corner?
	if (a[0] == pz(1, 1) && a[1] == pz(1, 2) && a[2] == pz(2, 1)) {
		if (xr == 1 || yr == 1) return 1;
		return 0;
	} else if (a[0] == pz(n-1, 1) && a[1] == pz(n, 1) && a[2] == pz(n, 2)) {
		if (xr == n || yr == 1) return 1;
		return 0;
	} else if (a[0] == pz(1, n-1) && a[1] == pz(1, n) && a[2] == pz(2, n)) {
		if (xr == 1 || yr == n) return 1;
		return 0;
	} else if (a[0] == pz(n-1, n) && a[1] == pz(n, n-1) && a[2] == pz(n, n)) {
		if (xr == n || yr == n) return 1;
		return 0;
	}

	// Otherwise get the missing corner of the arrangement
	int mx = min(a[0].x, min(a[1].x, a[2].x));
	int my = min(a[0].y, min(a[1].y, a[2].y));
	int Mx = max(a[1].x, max(a[2].x, a[0].x));
	int My = max(a[1].y, max(a[2].y, a[0].y));

	vector<pz> b;
	b.emplace_back(mx, my);
	b.emplace_back(mx, My);
	b.emplace_back(Mx, my);
	b.emplace_back(Mx, My);

	pz miss;

	for(auto bb: b){
		bool ew = true;
		rep(i,0,3){
			if (bb == a[i]){
				ew = false;
			}
		}
		if (ew) miss = bb;
	}

	// if (a[0].x == a[1].x){
	// 	miss = pz(Mx, my);
	// } else if (a[0].y != a[1].y){
	// 	miss = pz(mx, my);
	// } else if (a[0].x == a[2].x){
	// 	miss = pz(Mx, My);
	// } else {
	// 	miss = pz(mx, My);
	// }
	// cout << miss.x << " " << miss.y << endl;

	// cout << (abs(miss.x - xr) % 2 == 0) & (abs(miss.y - yr) == 0) << endl;
	if ((abs(miss.x - xr) % 2 == 0) && (abs(miss.y - yr) % 2 == 0)){
		return 0;
	}
	return 1;

	// cout << (abs(miss.x - xr) % 2 == 0) << " " << (abs(miss.y - yr) % 2 == 0) << endl;
	// return ( (abs(miss.x - xr) % 2 != 0) ||  );


	// return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int y1, x1, y2, x2, y3, x3;
		cin >> y1 >> x1 >> y2 >> x2 >> y3 >> x3;
		int yr, xr;
		cin >> yr >> xr;

		vector<pz> a;
		a.emplace_back(x1, y1);
		a.emplace_back(x2, y2);
		a.emplace_back(x3, y3);
		sort(all(a));

		if (check(a, xr, yr, n)){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		
	}
}