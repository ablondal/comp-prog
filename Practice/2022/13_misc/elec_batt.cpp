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
	int a, b, c, d, t;
	cin >> a >> b >> c >> d >> t;
	bool w = (abs(a-c) + abs(b-d) <= t) && ((abs(a-c) + abs(b-d) - t)%2 == 0);
	cout << (w ? "Y" : "N") << endl;
}