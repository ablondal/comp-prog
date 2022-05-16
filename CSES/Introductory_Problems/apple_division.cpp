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
	vll p(n);
	ll tw = 0;
	rep(i,0,n){
		cin >> p[i];
		tw += p[i];
	}
	ll M = 1e10;
	rep(m,0,(1<<n)){
		ll s = 0;
		rep(i,0,n){
			if ( (1<<i) & m ) {
				s += p[i];
			}
		}
		M = min(M, abs(2*s - tw));
	}
	cout << M << endl;
}