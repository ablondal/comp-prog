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
const int MX = 1e3+7;

gp_hash_table<int, int> M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		M.clear();
		int n;
		cin >> n;
		string S;
		cin >> S;
		ll tot = 0;
		ll curr = 0;
		rep(i,0,n){
			M[curr]++;
			curr += S[i] - '0' - 1;
			if (M.find(curr) != M.end()) tot += M[curr];
		}
		cout << tot << endl;
	}

}