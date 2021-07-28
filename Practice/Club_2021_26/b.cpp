#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<int, int> corners[4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll n, m, i, j;
		cin >> n >> m >> i >> j;
		i--;
		j--;
		n--;
		m--;
		ll M = 0;
		pair<int, int> ca1, ca2;
		rep(k,0,3){
			rep(l,k+1,4){
				auto c1 = corners[k];
				auto c2 = corners[l];
				ll ss = abs(c1.first*n - i) + abs(c1.second*m - j)
					+ abs(c1.first*n - c2.first*n) + abs(c1.second*m - c2.second*m)
					+ abs(c2.first*n - i) + abs(c2.second*m - j);
				M = max(M, ss);
				if (M == ss) {
					ca1 = c1;
					ca2 = c2;
				}
			}
		}
		printf("%lld %lld %lld %lld\n", ca1.first*n+1, ca1.second*m+1, ca2.first*n+1, ca2.second*m+1);
	}
}