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
	string s;
	ll a, b, c;
	cin >> a >> b;
	c = b-a+1;
	ll tot = 0;
	for(ll i = 1; i*i <= b; ++i){

		for(ll j = ((a+i-1)/i)*i; j <= b; j += i){
			if (i <= j/i){
				tot += i;
				if (i!=j/i) tot += j/i;
			}
		}
	}
	
	cout << tot << endl;
}