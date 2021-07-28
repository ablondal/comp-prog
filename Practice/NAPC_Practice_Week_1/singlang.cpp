#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
11: 30
12: 25

12345: at 123, get:
	a 1: -> 1
	a 2: -> 0
	a 3: -> 0
	a 4: -> 4
	a 5: -> 0

123
[0,0,0]
DP[1] = 3
DP[2] = (1+DP[1])*sz(A) - DP[1] = 9
DP[3] = (1+DP[2])*sz(A) - DP[1] = 27

s: 1 2 1 2 3 1 2 3
i: 1 2 3 4 5

s: [:1] = 1
DP[3] = ? - 0

s: [:2] = 12
DP[4] = ? - DP[3]

*/

vi Z(vi S){
	vi z(sz(S));
	int l=-1, r=-1;
	rep(i,1,sz(S)){
		z[i]=i >= r ? 0 : min(r-i, z[i-l]);
		while(i+z[i]<sz(S) && S[i+z[i]]==S[z[i]]){
			z[i]++;
		}
		if(i+z[i]>r){
			l=i;
			r=i+z[i];
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a, t;
	cin >> a >> t;
	while(t--){
		int n;
		cin >> n;
		vi s(n);
		rep(i,0,n){
			cin >> s[i];
		}
		auto z = Z(s);
		vector<vector<int>> deps(n);
		rep(i,0,n){
			if (i + z[i] < n){
				deps[i+z[i]].push_back(z[i]);
			}
		}
		vector<ll> DP(n+1, 0);
		DP[0] = a;
		rep(i,1,n){
			DP[i] = (1 + DP[i-1])*a;
			for(auto dd : deps[i]){
				DP[i] -= DP[dd];
			}
			DP[i] = (DP[i]%10000) + 10000;
			DP[i] %= 10000;
		}
		cout << DP[n-1] << endl;
	}
}