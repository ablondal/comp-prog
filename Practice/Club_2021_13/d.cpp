#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double pi = 3.141592653589793;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	// cin >> t;
	scanf("%d", &t);
	while(t--){
		double A, L;
		scanf("%lf%lf", &L, &A);
		// cin >> L >> A;
		double L2 = L*L;

		double area = pi * (A/360.0) * L2;

		area -= sin(A * pi / 180.0)*L2 / 2.0;



		// cout << setprecision(6) << area << endl;
		printf("%0.6lf\n", area);
	}
}