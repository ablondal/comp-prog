#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

long long DP[20][10] = {{0}};
long long good[20][10] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi t(n);
	for(int i=n-1; i>=0; --i){
		cin >> t[i];
	}
	// for(int i=0; i<100; ++i){
	// 	// DP[0][i] = i<t[0];
	// 	good[1][i/10] += (i<t[0]);
	// }
	for(int i=0; i<10; ++i){
		good[0][i] = i<t[0];
	}
	t.push_back(100);
	// rep(i,1,n*2){
	// 	if (i%2 == 1){
	// 		for(int j=0; j<100; ++j){
	// 			if (j<t[i/2]){
	// 				// Valid!
	// 				DP[i][j/10] += DP[i-1][j%10];
	// 				good[i][j/10] += good[i-1][j%10];
	// 			}
	// 		}
	// 	}else{
	// 		for(int j=0; j<100; ++j){
	// 			if ( (j/10) < t[i/2] ){
	// 				if ( j < t[(i/2) - 1] ){
	// 					good[i][j/10] += good[i-1][j%10];
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	for(int i=2; i<=n*2; i+=2){
		for(int j=0; j<1000; ++j){
			int hun = j/100;
			int ten = (j/10) % 10;
			int one = j%10;
			// cout << hun << " " << ten << " " << one << endl;

			if (
				hun < t[i/2] &&
				ten * 10 + one < t[ (i/2) - 1 ] &&
				hun * 10 + one < t[ (i/2) - 1 ] &&
				hun * 10 + ten < t[ (i/2) - 1 ]
			){
				// cout << j << endl;
				good[i][hun] += good[i-2][one];
				// cout << good[i][hun] << endl;
			}
		}
	}

	ll tot = 1;
	rep(i,0,n){
		tot *= t[i];
	}
	ll totgood = good[n*2][0];
	// rep(i,0,10){
	// 	// tot += good[n*2-1][i];
	// 	totgood += good[n*2-1][i];
	// }
	// cout << tot << endl;
	cout << tot - totgood << endl;
	// cout << 
}