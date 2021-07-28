#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 3e5+7;
const ll M = 1e9+7;

ll DPA[MAXN] = {0};
ll DPB[MAXN] = {0};
ll used[1000] = {0};
int big[1000] = {0};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int r, g;
	cin >> r >> g;
	int n = r+g;
	rep(i,1,1000){
		used[i]=used[i-1]+i; 
	}
	DPA[r] = 1;
	big[1] = r+1;
	int u;
	rep(i,1,1000){
		u = false;
		swap(DPA, DPB);
		rep(j,max((int)(r-used[i]),0),big[i]){
			DPA[j] = DPB[j+i];
			if (used[i] + j <= n) DPA[j] += DPB[j];
			if (DPA[j]){
				u = true;
			}
			big[i+1] = max(big[i+1], j+1);
			DPA[j] %= M;
			// printf("%d %d: %d\n", i, j, DPA[j]);
		}
		if (!u){
			break;
		}
		// for(auto u: DP[i]){
		// 	u.second %= M;
		// 	if (u.first >= i+1){
		// 		auto it = DP[i+1].find(u.first-i-1);
		// 		if (it == DP[i+1].end()) DP[i+1][u.first-i-1] = u.second;
		// 		else (*it).second += u.second;
		// 	}
		// 	if (used[i+1] + u.first <= n){
		// 		auto it = DP[i+1].find(u.first);
		// 		if (it == DP[i+1].end()) DP[i+1][u.first] = u.second;
		// 		else (*it).second += u.second;
		// 	}
		// }
	}
	ll tot = 0;
	rep(i,0,r+1){
		tot = (tot + DPB[i]) % M;
	}
	cout << tot << endl;
}