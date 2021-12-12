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

ll DP[107][100007] = {{0}};

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
		int n = sz(s);
		rep(i,0,n){
			if (s[i]=='?' && s[n-i-1]!='?'){
				s[i] = s[n-i-1];
			}
			if (s[n-i-1]=='?' && s[i]!='?'){
				s[n-i-1] = s[i];
			}
			if (s[i]=='0') a--;
			if (s[i]=='1') b--;
			if (s[i] != s[n-i-1]){
				a=-1;
				b=-1;
			}
		}
		rep(i,0,n){
			if (s[i] != '?') continue;
			if (i == n-i-1 && (a%2==1)){
				s[i] = '0';
				a--;
			} else if (i==n-i-1 && (b%2==1)){
				s[i] = '1';
				b--;
			} else if (a>1){
				s[i] = s[n-i-1] = '0';
				a-=2;
			} else if (b>1){
				s[i] = s[n-i-1] = '1';
				b -=2;
			}
		}
		if (a == 0 && b==0){
			cout << s << endl;
		} else {
			cout << -1 << endl;
		}
	}
}