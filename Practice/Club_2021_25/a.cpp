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
		ll a, b;
		cin >> a >> b;
		if (a == b){
			cout << "0 0" << endl;
			continue;
		}
		ll c = abs(a-b);
		ll d = a % c;
		cout << c << " " << min(d, c-d) << endl;
	}
}