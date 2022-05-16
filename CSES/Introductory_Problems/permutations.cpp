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
	ll n;
	cin >> n;
	if (n == 2 || n == 3) {
		cout << "NO SOLUTION" << endl;
	} else {
		for(int i=2; i<=n; i+=2){
			cout << i << " ";
		}
		for(int i=1; i<=n; i+=2){
			cout << i << " ";
		}
		cout << endl;
	}
}