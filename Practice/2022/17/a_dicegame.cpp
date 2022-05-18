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
	vi a(8);
	rep(i,0,8) cin >> a[i];
	int b = 0, c = 0;
	rep(i,0,4) b += a[i];
	rep(i,4,8) c += a[i];
	if (b > c) cout << "Gunnar" << endl;
	else if (b < c) cout << "Emma" << endl;
	else cout << "Tie" << endl;
}