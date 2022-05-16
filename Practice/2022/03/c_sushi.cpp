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
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	vi r;
	int l = 0;
	rep(i,1,n){
		if (a[i] != a[i-1]) {
			r.push_back(i-l);
			l = i;
		}
	}
	r.push_back(n-l);
	int m = 0;
	rep(i,1,sz(r)){
		m = max(m, min(r[i], r[i-1]));
	}
	cout << m*2 << endl;
}