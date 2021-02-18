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
	string s;
	cin >> s;
	int i = 0;
	while(s[i]=='a' && i<sz(s)) i++;
	if (i==sz(s)){
		s[sz(s)-1] = 'z';
		cout << s << endl;
		return 0;
	}
	while(i<sz(s) && s[i]!='a'){
		s[i] -= 1;
		++i;
	}
	cout << s << endl;
}