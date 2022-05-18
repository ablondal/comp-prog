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

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	double a, b, s, m, n;
	while(true){
		cin >> a >> b >> s >> m >> n;
		if (m==0) break;
		printf("%0.2f %0.2f\n", atan2(b*n, a*m)*(180.0/PI), sqrt(a*a*m*m + b*b*n*n) / s);
	}
}