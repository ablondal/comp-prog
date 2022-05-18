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
typedef complex<ll> ci;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while(n){
		vector<ci> pts(n);
		rep(i,0,n){
			int x, y;
			cin >> x >> y;
			pts[i] = ci(x, y);
			// cout << pts[i] << endl;
		}
		int ct = 0;
		int ct2 = 0;
		ci mid = pts[n/2];
		for(auto pt : pts){
			ci t = pt - mid;
			ll a = t.real() * t.imag();
			if (a < 0){
				ct2++;
			} else if (a > 0){
				ct++;
			}
		}
		cout << ct << " " << ct2 << endl;

		cin >> n;
	}
}