#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int g[3007][3007] = {{0}};
int dct[6007][8] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	ll dots = 0;
	cin >> n >> m;
	g[0][1] = 1;
	rep(i,0,n){
		string s;
		cin >> s;
		rep(j,0,m){
			dots += s[j]=='.';
			g[i+1][j+1] = (s[j]=='.') & (g[i][j+1] | g[i+1][j]);
		}
	}
	// End not reachable
	if (!g[n][m]) {
		cout << ((dots)*(dots-1))/2 << endl;
		return 0;
	}
	ll n1s = 0;
	int last1 = 0;
	vector<pair<int, int>> regions;
	int flag = 1;
	rep(diag, 2, n+m+1){
		int ct = 0;
		for(int i = 1; i<=n; ++i) {
			if (diag-i < 1 || diag-i > m) continue;
			if (!g[i][diag-i]) continue;
			ct++;
		}
		if (ct == 1){
			n1s++;
			continue;
		} else if (ct == 2) {
			if (last1) {
				regions.push_back({last1, diag});
			}
			last1 = diag;
			flag = 0;
			dct[diag][1] = 1;
			dct[diag][2] = 1;
			for(int i = 1; i<=n; ++i) {
				if (diag-i < 1 || diag-i > m) continue;
				if (!g[i][diag-i]) continue;
				ct++;
				g[i][diag-i] = (1<<flag);
				flag++;
			}
			flag = 0;
		} else {
			for(int i = 1; i<=n; ++i) {
				if (diag-i < 1 || diag-i > m) continue;
				if (!g[i][diag-i]) continue;
				ct++;
				g[i][diag-i] = g[i-1][diag-i] | g[i][diag-i-1];
				dct[diag][g[i][diag-i]]++;
			}
		}
		
		
	}

	ll tot = 0;

	for(auto& [beg, end] : regions){
		// if (end == beg) continue;
		ll t1c = 0;
		ll t2c = 0;
		for(int i = beg; i<=end; ++i){
			int a = dct[i][2] + dct[i][6];
			int b = dct[i][4] + dct[i][6];
			t1c += (a == 1);
			t2c += (b == 1);
			if (a==1 && b==1) tot--;
			if (a==1) tot += t2c;
			if (b==1) tot += t1c;
		}
	}

	tot += ((dots - 1LL + dots - n1s) * n1s)/2LL;

	cout << tot << endl;


}