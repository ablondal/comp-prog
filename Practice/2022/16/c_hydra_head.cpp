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
typedef complex<double> cd;

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h,t;
	while(cin >> h >> t){
		if (h==0 && t==0) break;
		int tot = 0;
		if (t & 1) {
			tot++;
			t++;
		}
		tot += t / 2;
		h += t / 2;
		t %= 2;
		tot += h / 2;
		h %= 2;
		if (h) tot += 4;
		cout << tot << endl;
	}
}