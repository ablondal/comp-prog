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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string t;
	cin >> t;
	char a[3] = {'P', 'E', 'R'};
	int tot = 0;
	rep(i,0,sz(t)){
		if (t[i] != a[i%3]) tot++;
	}
	cout << tot << endl;
}