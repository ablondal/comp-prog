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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("alimagde.in","r",stdin);
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		int a = 0;
		int i = 1;
		ll tot = 0;
		while(a <= n){
			if (a+i <= n){
				tot += (i-1);
				a += i;
			} else {
				tot += (n-a);
				a += i;
			}
			i++;
		}
		cout << tot << endl;
	}
}