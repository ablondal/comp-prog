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
		int n;
		cin >> n;
		vi a(n);
		rep(i,0,n) cin >> a[i];
		int div2 = 0;
		int other = 0;
		rep(i,0,n){
			if (a[i]%2==0){
				div2++;
				continue;
			}
			rep(j,i+1,n){
				if (a[j]%2==0) continue;
				if (__gcd(a[i], a[j]) != 1){
					other++;
				}
			}
		}
		cout << other + ( (n-1+n-div2) * div2 ) / 2 << endl;
	}
}