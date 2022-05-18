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
	int n, k;
	cin >> n >> k;
	rep(i,0,n){
		int a;
		cin >> a;
		while(a % 2 == 0){
			k--;
			a/=2;
		}
	}
	if (k <= 0){
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
}