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
	int n; cin >> n;
	vi a(n); rep(i,0,n) cin >> a[i];
	int n_plus = 0;
	string prog;
	for(int i=n-1; i>=0; i--){
		int b = a[i] + n_plus;
		while(b != 1){
			if (b & 1){
				prog.push_back('+');
				prog.push_back('1');
				b ^= 1;
				n_plus++;
			}
			prog.push_back('+');
			prog.push_back('d');
			b /= 2;
			n_plus++;
		}
		prog.push_back('1');
	}
	reverse(all(prog));
	cout << prog << endl;
}