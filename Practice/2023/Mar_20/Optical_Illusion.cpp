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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double n, r;
	cin >> n >> r;
	// cout << PI << endl;
	double p = sin(PI / n);
	cout << setprecision(20) << (p*r) / (1-p) << endl;
}