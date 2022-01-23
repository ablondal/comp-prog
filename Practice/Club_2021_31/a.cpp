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
	string s;
	cin >> s;
	bool w = true;
	rep(i,0,sz(s)){
		rep(j,i+1,sz(s)){
			if (s[i]==s[j]){
				w = false;
			}
		}
	}
	cout << w << endl;
}