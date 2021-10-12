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
	int n;
	cin >> n;
	while(n--){

		ll t;
		cin >> t;
		int ct = 0;
		while(t%5 == 0){
			ct += 3;
			t /= 5;
		}
		while(t%3 == 0){
			ct += 2;
			t /= 3;
		}
		while(t%2 == 0){
			ct += 1;
			t /= 2;
		}
		if (t == 1)
			cout << ct << endl;
		else
			cout << -1 << endl;
	}
}