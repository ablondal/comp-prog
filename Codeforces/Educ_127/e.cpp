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
ll mod = 998244353;

char c[1<<19] = {0};
ll DP[1<<19] = {0};
string fstr[1<<19];

void dfs(int v){
	fstr[v].push_back(c[v]);
	if (c[2*v] == 0){
		// fstr[v].push_back(c);
		DP[v] = 1;
	} else {
		dfs(2*v);
		dfs(2*v+1);
		// cout << fstr[2*v] << " " << fstr[2*v+1] << endl;
		if (fstr[2*v] == fstr[2*v+1]) {
			DP[v] = DP[2*v]*DP[2*v+1];
			DP[v] %= mod;
			fstr[v] += fstr[2*v];
			fstr[v] += fstr[2*v];
		} else {
			DP[v] = 2*DP[2*v]*DP[2*v+1];
			DP[v] %= mod;
			if (fstr[2*v] < fstr[2*v+1]){
				fstr[v] += fstr[2*v];
				fstr[v] += fstr[2*v+1];
			} else {
				fstr[v] += fstr[2*v+1];
				fstr[v] += fstr[2*v];
			}
		}
		// cout << DP[2*v] << " " << DP[2*v+1] << " " << DP[v] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i,1,sz(s)+1) c[i] = s[i-1];
	dfs(1);
	cout << DP[1] << endl;
}