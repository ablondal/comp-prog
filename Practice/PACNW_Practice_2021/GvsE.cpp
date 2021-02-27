#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll g[6] = {1,2,3,3,4,10};
ll e[7] = {1,2,2,2,3,5,11};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
    int n = t;
    vector<ll> res;
	while(t--){
		ll cost = 0;
        rep(i,0,6){
            ll a;
            cin >> a;
            cost += g[i]*a;
        }
        rep(i,0,7){
            ll b;
            cin >> b;
            cost -= e[i]*b;
        }
        // cout << cost << endl;
        res.push_back(cost);
	}
    rep(i,1,n+1){
        cout << "Battle " << i << ": ";
        if (res[i-1]>0) cout << "Good triumphs over Evil" << endl;
        else if (res[i-1]<0) cout << "Evil eradicates all trace of Good" << endl;
        else cout << "No victor on this battle field" << endl;
    }
}
/*
3
1 1 1 1 1 1
1 1 1 1 1 1 1
0 0 0 0 0 10
0 1 1 1 1 0 0
1 0 0 0 0 0
1 0 0 0 0 0 0
*/