#include <bits/stdc++.h>
using namespace std;
// done
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
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		rep(i,0,sz(s)){
			if (s[i]=='0'){
				a--;
				if (s[sz(s)-1-i]=='1') a = -1;
			}
			else if (s[i]=='1') {
				b--;
				if (s[sz(s)-1-i]=='0') b = -1;
			}
			else if (s[sz(s)-1-i] == '1'){
				s[i] = '1';
				b--;
			}else if (s[sz(s)-1-i] == '0'){
				s[i] = '0';
				a--;
			}
		}
		rep(i,0,sz(s)/2){
			if (s[i] == '?') {
				if (a>1){
					s[i] = s[sz(s)-1-i] = '0';
					a -= 2;
				}else{
					s[i] = s[sz(s)-1-i] = '1';
					b -= 2;
				}
			}
		}
		if (sz(s) % 2 == 1 && s[sz(s)/2] == '?'){
			if (a == 1) {
				s[sz(s)/2] = '0';
				a--;
			}else{
				s[sz(s)/2] = '1';
				b--;
			}
		}
		if (a==0 && b==0){
			cout << s << endl;
		}else{
			cout << -1 << endl;
		}
	}
	
}