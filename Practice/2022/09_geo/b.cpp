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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double m, n, r;
	cin >> m >> n >> r;
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	double mind = 1e18;
	rep(i,0,n+1){
		double dist = (r / n) * (abs(i-ay) + abs(i-by)) ;
		dist += PI * (abs(ax-bx) / m) * (r / n) * i;
		mind = min(mind, dist);
	}
	cout << setprecision(18) << mind << endl;
}