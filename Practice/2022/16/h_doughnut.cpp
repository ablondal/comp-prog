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

int q(int a, int b){
	cout << "QUERY " << a << " " << b << endl;
	int r;
	cin >> r;
	return r;
}

void ans(int a){
	cout << "YES " << a << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	n /= 2;
	int lo = 0, hi = 5e8;
	int m = q(0, 5e8-1);
	if (m > n){
		while(hi-lo > 0){
			int md = hi/2 + lo/2 + (hi & lo & 1);
			int mdm = q(md, md+5e8-1);
			if (mdm > n) {
				lo = md+1;
			} else if (mdm < n) {
				hi = md-1;
			} else {
				lo = hi = md;
			}
		}
		ans(lo);
	} else if (m < n){
		while(hi-lo > 0){
			int md = hi/2 + lo/2 + (hi & lo & 1);
			int mdm = q(md, md+5e8-1);
			if (mdm < n) {
				lo = md+1;
			} else if (mdm > n) {
				hi = md-1;
			} else {
				lo = hi = md;
			}
		}
		ans(lo);
	} else {
		ans(0);
	}
}