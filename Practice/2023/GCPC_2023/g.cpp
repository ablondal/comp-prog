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
	int ct = 0;
	for(ll i=1; i<10; ++i){
		ll j = i;
		while(j <= n) {
			ct++;
			j = j*10 + i;
		}
	}
	while(n>=100){
		n /= 10;
		ct++;
	}
	ct++;
	cout << ct << endl;
}