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

int DP[2007] = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vi a(n);
		vi shif(n);
		rep(i,0,n){
			cin >> a[i];
			shif[i] = a[i] - 1 - i;
		}
		rep(si, 1, n){
			rep(i,0,n+1){
				DP[i] = 0;
			}
		}
		


	}
}