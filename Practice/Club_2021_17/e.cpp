#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll DP[3007][3007] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi num(n);
	set<int> targ;
	rep(i,0,n){
		cin >> num[i];
		num[i] -= i;
		targ.insert(num[i]);
	}
	vi tar(all(targ));

	rep(i,0,sz(tar)){
		DP[0][i] = abs(num[0]-tar[i]);
		if (i) DP[0][i] = min(DP[0][i], DP[0][i-1]);
	}

	rep(i,1,n){
		rep(j,0,sz(tar)){
			DP[i][j] = DP[i-1][j] + abs(num[i]-tar[j]);
			if (j) DP[i][j] = min(DP[i][j], DP[i][j-1]);
		}
	}
	cout << DP[n-1][sz(tar)-1] << endl;

}