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
		ll n;
		cin >> n;
		ll s = 0;
		rep(i,0,n){
			ll tmp;
			cin >> tmp;
			s+=tmp;
		}
		ll c = s % n;
		ll tot = (c)*(n-c);
		cout << tot << endl;
	}
}