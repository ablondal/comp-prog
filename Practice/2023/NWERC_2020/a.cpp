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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double n, k;
	cin >> n >> k;
	double d, s;
	cin >> d >> s;
	double dleft = k*s - d*n;
	dleft /= (n - k);
	if (dleft > 100 || dleft < 0) {
		cout << "impossible" << endl;
	} else {
		cout << setprecision(10) << dleft << endl;
	}
}