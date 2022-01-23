#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// Supports .order_of_key(x), counts number of elements less than x.
// Supports .find_by_order(n), returns iterator to nth element (0-indexed)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
    cin >> n;
    vi a(n);
    for_each(all(a), [](auto& b){cin >> b;});
    cin >> q;
    map<pair<int, int>, int> results;
    vector<pair<int, int>> queries;
    vector<tuple<int, int, int>> og_q;
    rep(i,0,q){
        int i,j,k;
        cin >> i >> j >> k;
        
    }
}