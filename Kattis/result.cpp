#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

// Make these global for easier time
vector<ll> nums;
vector<char> ops;

ll solve(function<ull(ull,ull)> func, ull def){
	int n = sz(nums);
	vector<vector<ull>> DP(n+1, vector<ull>(n+1, def));
	// This DP vector is the same as in Python, for ranges [i, j]
	for(int i=0; i<n; i++) DP[i][i] = nums[i]; // Default
	
	for(int d=1; d<n; d++){
		for(int i=0; i+d<n; i++){
			int j=i+d;
			for(int k=i; k<j; k++){
				DP[i][j] = func(DP[i][j],
					ops[k] == '*'
						? (DP[i][k] * DP[k+1][j])
						: (DP[i][k] + DP[k+1][j])
				);
			}
		}
	}
	return DP[0][n-1];
}

void parse(string s){
	ll cnum = 0;
	nums.clear();
	ops.clear();
	for(int i=0; i<sz(s); i++){
		if (s[i] == '+' || s[i] == '*'){
			ops.push_back(s[i]);
			nums.push_back(cnum);
			cnum = 0;
		} else {
			cnum *= 10;
			cnum += s[i]-'0';
		}
	}
	nums.push_back(cnum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(1){
		string s;
		cin >> s;
		if (s == "END") break;
		parse(s);
		cout << solve([](ull a, ull b){return min(a,b);}, 1ULL<<63)
			<< " " << solve([](ull a, ull b){return max(a,b);}, 0) << endl;
	}
}