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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	unordered_map<ll, ll> S;
	ll tot_sum = 0;
	ll minn = 1e7;
	ll pos = -1;
	S[0] = -1;
	rep(i,0,n){
		tot_sum += a[i];
		if (S.count(tot_sum)){
			minn = min(minn, i-S[tot_sum]);
			if (i-S[tot_sum] == minn){
				pos = S[tot_sum]+1;
			}
		}
		S[tot_sum] = i;
	}
	if (minn == 1e7) cout << -1 << endl;
	else cout << pos+1 << " " << minn << endl;
}