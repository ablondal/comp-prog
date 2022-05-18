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
	ll n;
	cin >> n;
	ll tot = 0;
	for(ll i=1; i<n+1; ++i){
		if (i == 1) {
			tot += 0;
		} else if (i == 2) {
			tot += 0;
		} else if (i == 3) {
			tot += 8;
		} else if (i == 4) {
			tot += 2*2;
			tot += 3*2;
			tot += 3*2;
			tot += 2;
			tot -= 2;
		} else {
			tot += 2*3;
			tot += 3*4;
			tot += (i-4)*2*4;
			tot -= 2;
		}
		cout << (i*i) * (i*i-1) / 2 - tot << endl;
	}
}