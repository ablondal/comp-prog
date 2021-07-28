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

tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> S;
// Supports .order_of_key(x), counts number of elements less than x.
// Supports .find_by_order(n), returns iterator to nth element (0-indexed)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		S.clear();
		int n, l, r;
		cin >> n >> l >> r;
		ll sum = 0;
		rep(i,0,n){
			int a;
			cin >> a;
			int lo = l-a;
			int hi = r-a;
			sum += S.order_of_key({hi, i}) - S.order_of_key({lo, -1});
			S.insert({a,i});
		}
		cout << sum << endl;
	}
}