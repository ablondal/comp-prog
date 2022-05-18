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
	int n, m;
	while(cin >> n >> m){
		if (n == -1) break;
		if (m == (n*(n-1))/2) {
			cout << "YES" << endl;
			rep(i,1,n+1){
				rep(j,i+1,n+1){
					cout << i << " " << j << endl;
				}
			}
		} else if (m == n){
			cout << "YES" << endl;
			rep(i,0,n){
				cout << (i+1) << " " << ((i+1)%n)+1 << endl;
			}
		} else if (n % 2 == 0 && m == (n*n)/4) {
			cout << "YES" << endl;
			rep(i,1,(n/2) + 1){
				rep(j,(n/2)+1, n+1){
					cout << i << " " << j << endl;
				}
			}
		} else {
			cout << "NO" << endl;
		}
	}
}