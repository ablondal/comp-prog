#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		unsigned long long n;
		cin >> n;
		unsigned long long ans = 1;
		if (n>=34ULL) ans = 0;
		unsigned long long i = 1;
		unsigned long long mod = (1LL << 32);
		while(i<=n && ans){
			ans = (ans * i) % mod;
			i++;
		}
		cout << ans << endl;
	}
}