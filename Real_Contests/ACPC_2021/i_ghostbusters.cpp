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

ll C[2007][2007] = {{0}};
const ll M = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	C[0][0] = 1;
	rep(i,0,2007){
		C[i][0] = 1;
		C[i][i] = 1;
	}
	rep(i,2,2007){
		rep(j,1,i){
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
		}
	}
	int n, m;
	cin >> n >> m;
	if (n <= m){
		cout << C[m][n] << endl;
	} else {
		n -= m;
		cout << C[n+m-1][m-1] << endl;
	}
}