#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// int DP[100007];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int m;
		cin >> m;
		vector<pair<int, int>> pts(m);
		rep(i,0,m){
			cin >> pts[i].first >> pts[i].second;
			pts[i].second *= -1;
		}
		sort(all(pts));
		vi DP(2,0);
		DP[1] = 0;
		DP[0] = -1e9+7;
		// DP[1] = 0;
		// DP[2] = 0;
		int j = 0;
		rep(i,0,m){
			// cout << pts[i].first << ' ' << pts[i].second << endl;
			// pts[i].second *= -1;
			// int lo = 0, hi = j;
			// while(hi-lo>1){
			// 	int mid = (hi+lo)>>1;
			// 	if (DP[mid]<pts[i].second){
			// 		lo = mid;
			// 	} else {
			// 		hi = mid;
			// 	}
			// }
			auto hi = upper_bound(DP.begin(), DP.end(), pts[i].second);
			
			*hi = pts[i].second;
			if (hi == DP.end()-1){
				j++;
				DP.push_back(0);
				// cout << "here" << endl;
			}
		}
		cout << (j) << endl;
	}
}