#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void factor(ll n){
	cout << n << ": ";
	for(ll i=2; i*i<=n; ++i){
		while(n % i == 0){
			cout << i << " ";
			n /= i;
		}
	}
	if (n > 1) {
		cout << n << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll k;
	cin >> k;
	factor(k);
	ll a = k+1;
	int ct = 0;
	while(true){
		if (k*a % (a-k) == 0) {
			cout << a << " " << (k*a) / (a-k) << endl;
			// factor(a);
			// factor((k*a)/(a-k));
			ct++;
		}
		if (k*a / (a-k) <= a ) {
			break;
		}
		a++;
	}
	cout << ct << endl;
}