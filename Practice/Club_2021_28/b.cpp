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
		string s;
		cin >> s;
		int m = 9;
		int a = 0;
		int b = 0;
		rep(i,0,10){
			if (i%2 == 0){
				// a
				if (s[i] == '1' || s[i] == '?') a++;
			}else {
				if (s[i] == '1') b++;
			}
			if (a-b > (10-i)/2) m = min(m, i);
		}
		 // m = 9;
		 a = 0;
		 b = 0;
		rep(i,0,10){
			if (i%2 == 0){
				// a
				if (s[i] == '1' ) a++;
			}else {
				if (s[i] == '1'|| s[i] == '?') b++;
			}
			if (b-a > (10-i-1)/2) m = min(m, i);
		}
		cout << m+1 << endl;
	}
}