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
	int h, v;
	cin >> h >> v;
	double p = PI*v/180.0;
	// cout << sin(p) << endl;
	double d = h / sin(p);
	cout << ceil(d) << endl;
}