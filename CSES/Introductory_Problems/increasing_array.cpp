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
	ll tot = 0;
	rep(i,0,n){
		cin >> a[i];
		if (i && a[i] < a[i-1]) {
			tot += a[i-1]-a[i];
			a[i] = a[i-1];
		}
	}
	cout << tot << endl;
	
}