#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll changes(ll x){
	ll sum = 0;
	ll add = 1;
	while(x > 0){
		while(x % 10){
			sum += add;
			x -= 1;
		}
		add *= 10;
		add += 1;
		x /= 10;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll l, r;
		cin >> l >> r;
		cout << changes(r) - changes(l) << endl;
	}
}