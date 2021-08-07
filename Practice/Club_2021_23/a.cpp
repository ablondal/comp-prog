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
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int w1 = max(a,b);
		int w2 = max(c,d);
		if ( (c > w1 && d > w1) || (a > w2 && b > w2) ){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
}