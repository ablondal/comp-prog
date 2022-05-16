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

int DP[31][31][31];

int calcDP(int i, int j, int k){
	if (i==0 || j == 0 || k == 0) return 0;
	if (k < j) swap(k,j);
	if (j < i) swap(i,j);
	if (k < j) swap(k,j);
	if (DP[i][j][k] != -1) return DP[i][j][k];

	if (i == 1 || j == 1 || k == 1) return DP[i][j][k] = 1;
	set<int> found;
	rep(x,0,(i+1)/2){
		rep(y,0,(j+1)/2){
			rep(z,0,(k+1)/2){
				int val = 0;
				val = (
					calcDP(x,y,z) ^
					calcDP(i-x-1,y,z) ^ calcDP(x,j-y-1,z) ^ calcDP(x,y,k-z-1) ^
					calcDP(i-x-1,j-y-1,z) ^ calcDP(i-x-1,y,k-z-1) ^ calcDP(x,j-y-1,k-z-1) ^
					calcDP(i-x-1,j-y-1,k-z-1)
					);
				found.insert(val);
			}
		}
	}
	int a=0;
	while(found.count(a)) a++;
	// cout << i << " " << j << " " << k << " " << a << endl;
	return DP[i][j][k] = a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	rep(i,0,31) rep(j,0,31) rep(k,0,31) {
		DP[i][j][k] = -1;
	}
	string p;
	cin >> p;
	int val = 0;
	int n;
	cin >> n;
	rep(i,0,n){
		int a,b,c;
		cin >> a >> b >> c;
		val ^= calcDP(a,b,c);
	}
	// cout << val << endl;
	if (p == "RUBEN"){
		cout << (val != 0 ? "RUBEN" : "ALBERT") << endl;
	} else {
		cout << (val != 0 ? "ALBERT" : "RUBEN") << endl;
	}
	// cout << ( (val != 0) ^ (p=="RUBEN") ? "ALBERT" : "RUBEN" ) << endl;
}