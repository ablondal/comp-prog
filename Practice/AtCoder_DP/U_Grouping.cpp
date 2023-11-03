#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

// This code heavily uses bitmasks to represent sets.
// This is particularly useful for exponential DP with N < ~25
// The idea is that all possible subsets of a set of size N
// are representable using the binary representation of an
// integer less than 2^N.
// Here, we need not only sets, but a way to quickly get all possible
// subsets of a set.

// We will use submasking code from:
// https://cp-algorithms.com/algebra/all-submasks.html
// Note that this is also in our codebook: section 10.5 of
// https://drive.google.com/file/d/1TQVl1uyBAbWCyIeE5F4uBG-4v5JWYuQN

ll a[16][16] = {{0}};
// Our scores

ll DP[1<<16] = {0};
// Memoizing the maximum possible score with all rabbits
// in this current bitmask already grouped.

// A helper function to calculate the value of a set of rabbits.
inline ll val(int mask){
	ll v = 0;
	rep(i,0,16){
		if (mask & (1<<i)) {
			// If rabbit i is in the mask
			rep(j,i+1,16){
				if (mask & (1<<j)) {
					// If rabbit j is in the mask
					v += a[i][j]; // Add the points
				}
			}
		}
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		rep(j,0,n){
			cin >> a[i][j];
		}
	}
	// Initialize all DP values with the option of putting all
	// their rabbits in a single group
	rep(i,0,1<<n) DP[i] = val(i);
	
	// Now do the DP!
	// For each mask, we will enumerate over all possible submasks,
	// and calculate the cost of adding a new group of Rabbits that
	// makes up the difference between the two sets.
	rep(m,1,1<<n){
		// m is the mask of rabbits we're finding the max value for grouping
		for(int s=m; s; s=(s-1)&m){
			// s is the "last group" we're adding to something to get
			// m to see if that improves DP[m].
			// This loop gives us all s that are subsets of m (except 0)
			int prev = m & (~s); // m without the elements of s.
			// Then, using s as an arbitrary splitting point,
			// the distribution of rabbits giving DP[m] its maximum
			// value must split along some s, and the grouping within
			// DP[s] and DP[prev] is already maximized (they are subsets,
			// they were processed earlier in the loop)
			// Thus, we'll hit the maximum value for DP[m] at some point this loop.
			DP[m] = max(
				DP[m], // To maximize, we compare the new value with the old one
				DP[prev] + DP[s]
			);
		}
	}
	// How does this run in time?
	// It looks like O( (2^n)^2 ), or O(2^(2n)) which would be O(2^32),
	// wayy too big.

	// Well, consider the inner loop. How many combinations of m and s do
	// we get?
	// For each of the n bits, either it is 0 in both of m and s (not in m),
	// 1 in m and 0 in s, or 1 in m and 1 in s.
	// Thus, there are only 3 possibilities per bit, and the total runtime is
	// O(3^n). 3^16 ~ 4.3e7, definitely fast enough to run, especially since
	// the computation in the inner loop is just addition and bitwise operations.
	cout << DP[(1<<n) - 1] << endl;
}