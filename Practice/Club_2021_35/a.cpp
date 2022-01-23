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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int a=0,b=0,c=0;
		for(auto ch : s){
			if (ch=='A') a++;
			if (ch=='B') b++;
			if (ch=='C') c++;
		}
		if (a+c == b) {
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}