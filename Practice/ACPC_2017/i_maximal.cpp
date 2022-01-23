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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_tree;
// Supports .order_of_key(x), counts number of elements less than x.
// Supports .find_by_order(n), returns iterator to nth element (0-indexed)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin >> n;

    int n_map = 0;
    vector<o_tree> poss;
    unordered_map<int, int> M;

    rep(i,0,n){
        int a;
        cin >> a;
        if (M.count(a)) {
            poss[M[a]].insert(i);
        } else {
            poss.push_back(o_tree());
            M[a] = n_map++;
            poss[M[a]].insert(i);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int i, m;
        cin >> i >> m;
        i--;
        vector<int> b;
        rep(j,0,m){
            int c;
            cin >> c;
            if (M.count(c)) {
                b.push_back(M[c]);
            }
        }
        int psum = 0;
        for(auto bb : b){
            psum += poss[bb].order_of_key(i);
        }
        int lo = 0, hi = n-i+3;
        while(hi-lo>1){
            int md = (hi+lo)/2;
            int ssum = 0;
            for(auto bb : b){
                ssum += poss[bb].order_of_key(i+md);
            }
            if (ssum - psum == md){
                lo = md;
            } else {
                hi = md;
            }
        }
        cout << lo << endl;
    }

}