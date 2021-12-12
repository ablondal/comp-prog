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

int g_f[5007][5007] = {{0}};
int g_b[5007][5007] = {{0}};
int ctt[5007] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = sz(s);
	rep(i,0,n){
		if (s[i] == '(') ctt[i+1] = ctt[i]+1;
		else ctt[i+1] = ctt[i]-1;
	}
	rep(i,0,n){
		int ct = 0;
		int minct = 0;
		rep(j,i,n){
			if (s[j]=='(') ct++;
			else ct--;
			minct = min(minct, ct);
			g_f[i][j] = minct;
		}
	}
	rep(i,0,n){
		int ct = 0;
		int minct = 0;
		rep(j,i,n){
			if (s[j]==')') ct++;
			else ct--;
			minct = min(minct, ct);
			g_b[i][j] = minct;
		}
	}
	bool g = (g_f[0][n-1] == 0 && ctt[n] == 0);
	rep(i,0,n){
		if (ctt[i]>=0 && (i==0 || g_f[0][i-1]>=0) ) {
			rep(j,i,n){
				if (ctt[n] - 2*(ctt[j+1]-ctt[i]) == 0){
					// cout << i << j << endl;
					if (ctt[i] + g_b[i][j] >= 0){
						if (ctt[i] + (ctt[i]-ctt[j+1]) + g_f[j+1][n-1] >= 0){
							g = true;
						}
					}
				}
			}
		}
	}
	cout << (g ? "possible" : "impossible") << endl;

}