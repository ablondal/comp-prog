#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int G[1007][1007] = {{0}};
char L[1007][1007] = {{0}};
char R[1007][1007] = {{0}};
char U[1007][1007] = {{0}};
char D[1007][1007] = {{0}};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, m;
	cin >> n >> m;
	rep(i,0,n){
		rep(j,0,m){
			cin >> G[i][j];
		}
	}
	rep(i,0,n){
		bool y = false;
		rep(j,0,m){
			if (G[i][j]) y = true;
			L[i][j] = y;
		}
		y = false;
		for(int j=m-1; j>=0; --j){
			if (G[i][j]) y = true;
			R[i][j] = y;
		}
	}
	rep(j,0,m){
		bool y = false;
		rep(i,0,n){
			if (G[i][j]) y = true;
			U[i][j] = y;
		}

		y = false;
		for(int i=n-1; i>=0; --i){
			if (G[i][j]) y = true;
			D[i][j] = y;
		}
	}
	ll tot = 0;
	rep(i,0,n) rep(j,0,m){
		if (!G[i][j]) {
			tot += L[i][j] + R[i][j] + U[i][j] + D[i][j];
		}
	}
	cout << tot << endl;
}