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
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	s = '0' + s + '0';
	vi a;
	for(auto c : s) a.push_back(c-'0');
	int tot = 0;
	rep(i,0,sz(a)){
		if (a[i]) {
			tot++;
			if (i+1 < sz(a) && a[i+1]) {
				a[i+2] += a[i+1];
				a[i+1] = 0;
			}
		}
	}
	cout << tot << endl;

	
}