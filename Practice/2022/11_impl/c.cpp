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
	int n, p;
	cin >> n >> p;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	int M = 0;
	int c = 0;
	rep(i,0,n){
		c += a[i]-p;
		if (c < 0) c = 0;
		M = max(M, c);
	}
	cout << M << endl;
}