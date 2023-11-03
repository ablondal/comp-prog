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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<string> a(n);
		int c[5] = {0};
		rep(i,0,n){
			cin >> a[i];
		}
		int M = 0;
		vector<int> sc(n);
		rep(i,0,5){
			sc.assign(n,0);
			rep(j,0,n){
				for(auto cc : a[j]){
					if (cc-'a' == i){
						sc[j]++;
					} else {
						sc[j]--;
					}
				}
			}
			sort(all(sc));
			reverse(all(sc));
			int b = 0;
			int ss = 0;
			while(b < n && ss + sc[b] > 0){
				ss += sc[b];
				b++;
			}
			M = max(M, b);
		}
		cout << M << endl;
	}
}