#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

inline bool in(long double x, long double y, long double x1, long double x2, long double y1, long double y2){
	return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	bool works = false;
	using ld = long double;
	ld x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

	ld xs[6] = {x1, x2, x3, x4, x5, x6};
	ld ys[6] = {y1, y2, y3, y4, y5, y6};

	rep(j, 0, 1e6){
		int xi = rand() % 6;
		int yi = rand() % 6;
		ld x_c = rand() % 3;
		ld y_c = rand() % 3;
		ld x = xs[xi] + (x_c - 1)*0.5;
		ld y = ys[yi] + (y_c - 1)*0.5;
		if (in(x,y,x1,x2,y1,y2) && !in(x,y,x3,x4,y3,y4) && !in(x,y,x5,x6,y5,y6)) {
			works = true;
			// cout << x << " " << y << endl;
		}
	}

	if (works) cout << "YES" << endl;
	else cout << "NO" << endl;
	// cout << works ? "YES" : "NO" << endl;
}