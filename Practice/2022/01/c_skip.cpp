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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, x;
	ll g, tmp;
	cin >> n >> x;
	rep(i,0,n){
		cin >> tmp;
		if (i == 0) g = abs(tmp-x);
		else {
			g = gcd(g, abs(tmp-x));
		} 
	}
	cout << g << endl;
}