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
	int ans;
	if(t==0) ans = 1;
	else if(t==1) ans = 2;
	else{
		ans = 1;
		while(t){
			if (t & 1) ans *= 2;
			t = (t >> 1);
		}
	}
	cout << ans << endl;
}