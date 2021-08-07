#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e6+7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ordered_set b4;
	ordered_set after;
	int n;
	cin >> n;
	vi a(n);
	vi strong_b4(n);
	vi weak_after(n);
	rep(i,0,n){
		cin >> a[i];
		strong_b4[i] = i - b4.order_of_key(a[i]);
		b4.insert(a[i]);
	}
	for(int i=n-1; i>=0; --i){
		weak_after[i] = after.order_of_key(a[i]);
		after.insert(a[i]);
	}
	ll tot = 0;
	rep(i,0,n){
		tot += (ll)strong_b4[i] * (ll)weak_after[i];
	}
	cout << tot << endl;
	
}