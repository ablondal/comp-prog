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
	ll n, p, x, y;
	cin >> n >> p >> x >> y;
	ll tim = p / (n-1);
	// if (p % n == 0){

	// }
	ll tot = p * x + (tim) * y;
	cout << tot << endl;

	// cout << x * (n-1) + y 
}