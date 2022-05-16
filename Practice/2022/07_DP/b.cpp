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
const int MX = 1e5+7;
int DP[MX] = {0};
int H[MX] = {0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		long long a=1, tot=0;
		while(a<=n){
			tot-=a*2;
			a*=2;
		}
		tot += (n+1)*(n)/2;
		cout << tot << endl;
	}
}