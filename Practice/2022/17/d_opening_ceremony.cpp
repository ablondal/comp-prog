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
	vll a(n);
	rep(i,0,n) cin >> a[i];
	sort(all(a));
	reverse(all(a));
	ll M = a[0];
	a.push_back(0);
	rep(i,0,n){
		M = min(M, i+1+a[i+1]);
	}
	cout << M << endl;
}