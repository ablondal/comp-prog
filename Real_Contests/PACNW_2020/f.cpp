
#include "bits/stdc++.h"
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// bool test_der(int[] perm, int n){

// }

ll p2[1000007];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string S;
	ll n, p;
	cin >> n >> p;

	p2[0] = 1;
	rep(i,1,1000007){
		p2[i] = (p2[i-1]*2)%p;
	}

	ll tot = 0;
	rep(i,2,n){
		tot += p2[__gcd(i, (int)n)-1]-1;
		tot %= p;
	}
	tot *= (n-2);
	tot %= p;
	cout << tot << endl;
}