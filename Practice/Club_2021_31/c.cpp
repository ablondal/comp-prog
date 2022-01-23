#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[107][2] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int st = 0;
		while(st < n && s[st] == '?') st++;
		if (st == n) {
			s[n-1] = 'B';
		}
		st--;
		while(st>=0){
			if (s[st+1] == 'B') s[st] = 'R';
			else s[st] = 'B';
			st--;
		}
		rep(i,st,n){
			if (s[i] == '?'){
				if (i) {
					if (s[i-1] == 'B') s[i] = 'R';
					else s[i] = 'B';
				} else {
					if (n>1){
						if (s[i+1] == 'B') s[i] = 'R';
						else s[i] = 'B';
					} else {
						s[i] = 'B';
					}
				}
			}
		}
		cout << s << endl;
	}
}