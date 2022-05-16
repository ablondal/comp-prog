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
	if ( ((n+1) / 2) & 1){
		cout << "NO" << endl;
		exit(0);
	}
	cout << "YES" << endl;
	vi a, b;
	ll sa=0, sb=0;
	for(ll i=n; i>=1; --i){
		if (sa < sb){
			a.push_back(i);
			sa += i;
		} else {
			b.push_back(i);
			sb += i;
		}
	}
	cout << sz(a) << endl;
	for(auto e: a) cout << e << " ";
	cout << endl << sz(b) << endl;
	for(auto e: b) cout << e << " ";
	cout << endl;
}