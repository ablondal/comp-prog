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
	vi a(n+1, 0);
	rep(i,0,n-1){
		int b;
		cin >> b;
		a[b] = 1;
	}
	rep(i,1,n+1){
		if (a[i]==0){
			cout << i << endl;
		}
	}
}