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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	vi a(t);
    rep(i,0,t) cin >> a[i];
    sort(all(a));
    ll sum = 0;
    rep(i,0,t) sum += a[i];
    cout << min(sum/2, sum - a[t-1]) << endl;
}