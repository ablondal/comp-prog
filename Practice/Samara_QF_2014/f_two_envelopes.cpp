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
	int a, b, c;
	cin >> a >> b >> c;
	bool stay;
	if (b < c) {
		stay = true;
	} else if (c % 2 == 1) {
		stay = false;
	} else if ( (c/2) < a ) {
		stay = false;
	} else {
		stay = false;
	}
	if (stay) {
		cout << "Stay with this envelope" << endl;
	} else {
		cout << "Take another envelope" << endl;
	}
}