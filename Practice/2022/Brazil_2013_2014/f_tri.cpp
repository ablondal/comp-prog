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
	int tot = 0;
	rep(i,0,n){
		cin >> a[i];
		tot += a[i];
		if (i) a[i] += a[i-1];
	}
	unordered_map<int, int> M;
	if (tot % 3 != 0){
		cout << 0 << endl;
		return 0;
	}
	rep(i,0,n){
		M[a[i]%(tot/3)]++;
	}
	int ans = 0;
	for(auto& [u,v] : M){
		if (v>=3) ans++;
	}
	cout << ans << endl;
}