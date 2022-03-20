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
const int MX = 1e6+7;

ll P2[MX];

ll calc(int l, int r, int c, int n){
	if (r-l==2){
		if (c == (r+l)/2) n++;
		return P2[n/2];
	} else if (r-l==1) {
		return P2[(n+1)/2]+P2[n/2]-1;
	} else if (r==l) {
		return 2*P2[n/2] + P2[(n+1)/2] - 2;
	} else {
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long N, M;
	string s;
	cin >> N >> M;
	cin >> s;
	P2[0] = 1;
	rep(i,1,MX) P2[i] = (P2[i-1]<<1)%M;
	// cout << calc(0,0,0,N) << endl;
	int l=0, r=0, c=0;
	ll ans = 0;
	rep(i,0,N){
		if (s[i]=='L'){
			c++;
			r = max(r,c);
			continue;
		}
		ans += calc(l, max(r,c+1), c+1, N-i-1);
		ans %= M;
		c--;
		l = min(l,c);
	}
	cout << (ans+1)%M << endl;
}