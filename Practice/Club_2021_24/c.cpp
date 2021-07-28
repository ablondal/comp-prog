#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

ld a[(int)1e5+7];

ld binpow(ld x, int n){
	ld prob = 1;
	while(n){
		if (n & 1) prob *= x;
		x *= x;
		n >>= 1;
	}
	return prob;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,n;
	cin >> m >> n;
	ld tot = 0;
	ld mi = 1.0 / m;
	rep(i,1, m+1){
		ld mi = ((ld)i)/m;
		ld mii = ((ld)i-1)/m;
		tot += i * (binpow(mi, n) - binpow(mii, n));
	}
	cout << setprecision(20) << tot << endl;
}