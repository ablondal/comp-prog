
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int D[10][10] = {{0}}; 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string S;
	cin >> S;

	rep(i,1,sz(S)){
		D[S[i-1]-'1'][S[i]-'1']++;
	}

	// rep(i,0,9){
	// 	rep(j,0,9) cout << D[i][j] << " ";
	// 	cout << endl;
	// }
	int perm[] = {1,2,3,4,5,6,7,8,9};
	// int perm[] = {9, 8, 7, 6, 5, 1, 3, 4, 2};

	ll M = 1e16;

	do{
		ll val = sz(S) + abs(perm[S[0]-'1']-1);
		rep(i,0,9){
			rep(j,0,9){
				val += D[i][j] * (abs(perm[i]-perm[j]));
				// cout << D[i][j] * (abs(perm[i]-perm[j]));
			}
			// cout << endl;
		}
		M = min(M, val);
		// if (M == val){
		// 	// cout << val << endl;
		// 	// rep(i,0,9) cout << perm[i] << " ";
		// 	cout << endl;
		// }
	}while(next_permutation(perm, perm+9));
	cout << M << endl;
}