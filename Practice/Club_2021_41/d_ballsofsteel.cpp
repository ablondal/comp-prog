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
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<cd> bs(n);
		rep(i,0,n){
			double x,y;
			cin >> x >> y;
			bs[i] = {x,y};
		}
		bool W = false;
		rep(i,0,n){
			bool y = true;
			rep(j,0,n){
				cd a = bs[i]-bs[j];
				if (abs(a.real()) + abs(a.imag()) > k){
					y = false;
					break;
				}
			}
			if (y) W = true;
		}
		cout << (W ? "1" : "-1") << endl;
	}
}