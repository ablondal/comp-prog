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

int ans = 0;
char grid[8][8];
bool d1[64] = {0};
bool d2[64] = {0};
bool h[8] = {0};

void dfs(int x){
	// cout << x << endl;
	if (x == 8) {
		ans++;
		return;
	}
	rep(y,0,8){
		if (grid[y][x] == '*' || h[y] || d1[x+y] || d2[16+x-y]) continue;
		
		h[y] = d1[x+y] = d2[16+x-y] = true;
		dfs(x+1);
		h[y] = d1[x+y] = d2[16+x-y] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	rep(i,0,8){
		string s;
		cin >> s;
		rep(j,0,8){
			grid[i][j] = s[j];
		}
	}
	dfs(0);
	cout << ans << endl;
}