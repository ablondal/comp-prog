#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef bitset<2007> BS;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("binary.in","r",stdin);
	int n, x;
	string s;
	cin >> n >> x >> s;
	int k = 1;
	for(;k<n; ++k){
		// int ops = 0;

		BS DP;
		DP[0] = 1;

		// vi DP(x+1, 0);
		// DP[0] = 1;

		for(int i = 0; i<k; ++i){
			int ct0 = 0;
			int ct1 = 0;
			for(int j=i; j<n; j+=k){
				if (s[j]=='1') ct1++;
				else ct0++;
			}

			DP = (DP << ct0) | (DP << ct1);

			// for(int j=x; j>=0; j--){
			// 	if (DP[j] == 0) continue;

			// 	if (j+ct0 <=x) DP[j+ct0] = 1;
			// 	if (j+ct1 <=x) DP[j+ct1] = 1;
			// 	if (ct0 != 0 && ct1 != 0) DP[j] = 0;
			// }
		}

		if (DP[x]){
			break;
		}
	}
	cout << k << endl;

}