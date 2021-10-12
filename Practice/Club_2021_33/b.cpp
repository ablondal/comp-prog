#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int ff = -1;
		int num = 0;
		int last = -1;
		int i=0;
		while(i<sz(s)){
			if (s[i]=='*') {
				if (ff == -1) {
					ff = i;
					num++;
				} else if (i - ff > k) {
					ff = last;
					num++;
				}
				last = i;
			}
			i++;
		}
		if (ff != last)
			num++;
		cout << num << endl;
	}
}