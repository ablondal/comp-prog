
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	vi a(t);
	rep(i,0,t) cin >> a[i];
	sort(all(a));
	ll sum = 0;
	rep(i,0,t){
		if (i==0 || a[i]!=a[i-1]+1){
			sum += a[i];
		} 
	}
	cout << sum << endl;
}