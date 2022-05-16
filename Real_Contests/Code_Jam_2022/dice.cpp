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
	rep(T, 1, t+1){
		cout << "Case #" << T << ": ";
		
		int n;
		cin >> n;
		vi a(n);
		rep(i,0,n) cin >> a[i];
		sort(all(a));
		int j = 1, i = 0;
		while(i < n){
			if (a[i] >= j) {
				j++;
				i++;
			} else {
				i++;
			}
		}
		cout << j-1 << endl;

	}
}