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
	int n, k;
	cin >> n >> k;
	vector<pii> ivals(n);
	rep(i,0,n) cin >> ivals[i].first >> ivals[i].second;
	rep(i,0,n) ivals[i].second += ivals[i].first;

	multiset<int> endtimes;
	int tot = 0;
	vi a(n, 0), b(n, 0);
    rep(i,0,n){
        int ct = ivals[i].first;
        while(sz(endtimes) && *endtimes.begin() <= ct) {
            endtimes.erase(endtimes.begin());
        }
        if (sz(endtimes) < k) {
            endtimes.insert(ivals[i].second);
            tot++;
        } else {
            auto it = endtimes.end();
            it--;
            if (*it > ivals[i].second) {
                endtimes.erase(it);
                endtimes.insert(ivals[i].second);
            }
        }
        a[i] = tot;
    }
    // int tot2 = 0;
    tot = 0;
    multiset<int> S;
    rep(i,0,n){
    	int ct = ivals[i].first;
    	while (sz(S) && *S.begin() <= ct){
    		S.erase(S.begin());
    	}
    	if (sz(S) < k) {
    		S.insert(ivals[i].second);
    		tot++;
    	}
    	b[i] = a[i] - tot;
    }
    rep(i,0,n) cout << b[i] << endl;
    // cout << tot << endl;
}