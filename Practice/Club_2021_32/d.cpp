#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll a[407];

// DP[l][r] is the min cost of aggregating the slimes in the range
// [l, r) into one slime (left-inclusive, right-exclusive)
ll DP[407][407];

// This is used to quickly calculate the sum of any range of
// array a: sum( a[l] + ... + a[r] ) = asum[r] - asum[l]
ll asum[407] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	// Get input, and initialize DP and asum
	rep(i,0,n){
		cin >> a[i];
		DP[i][i+1] = 0;
		asum[i+1] = asum[i] + a[i];
	}

	rep(siz,2,n+1){
		rep(l,0,n+1-siz){
			int r = l+siz;
			DP[l][r] = 1e18; // Init as infinite cost
			// So cost always goes down.
			rep(m,l+1,r){
				// Take the new value only if it's lower
				// than the current value
				DP[l][r] = min(
					DP[l][r],
					DP[l][m] + DP[m][r] + asum[r]-asum[l]
				);
			}
		}
	}
	// Min cost of merging all slimes
	cout << DP[0][n] << endl;
}