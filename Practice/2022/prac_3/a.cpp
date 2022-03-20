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
	unordered_map<int, int> P;
	int n;
	cin >> n;
	int M = n;
	vi a(n);
	rep(i,0,n){
		cin >> a[i];
		if (P.count(a[i])){
			M = min(M, i-P[a[i]]);
		}
		P[a[i]] = i;
	}
	// if (M==-1){
	// 	M = n;
	// }
	cout << M << endl;
}