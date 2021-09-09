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
		int k;
		cin >> k;
		int tot = 0;
		int a = 1;
		int i = 1;
		int y, x;
		while(tot + a < k){
			tot += a;
			a += 2;
			i++;
		}
		if (tot + i >= k){
			x = i;
			y = k-tot;
		} else {
			y = i;
			x = i - (k - (tot+i));
		}
		cout << y << " " << x << endl;
	}
}