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
const double PI = acos(-1);

double alph, bet, N;
double ab;

// Area from 0 to ang
double arrr(double ang){
	double aa = 0.5 * bet * bet * ang;
	aa += 0.25 * bet * (ab / PI) * ang * ang;
	aa += ((ab*ab)/(24*PI*PI))*ang*ang*ang;
	return aa;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> alph >> bet >> N;
	alph = alph + bet;
	ab = alph - bet;
	double tota = arrr(2*PI);

	rep(i,1,(int)N){
		double ii = i;
		double lo = 0, hi = 2*PI;
		while(hi-lo > 1e-9){
			double md = (hi+lo)/2;
			if (arrr(md) <= tota * (ii/N)) {
				lo = md;
			} else {
				hi = md;
			}
			// cout << md << " " << area(md) << endl;
		}
		cout << setprecision(15) << lo << endl;
	}

	// cout << area(2*PI) << endl;
}