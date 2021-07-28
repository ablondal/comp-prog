#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DFS(int mask, )

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	while(m && n){
		vi a(n, 0);
		rep(i,0,n){
			string s;
			cin >> s;
			rep(j,0,m){
				a[i] |= (s[j]=='1') << j;
			}
		}
		int M = 0;
		rep(mask, 0, (1<<m)){
			vi b(n);
			rep(i,0,n){
				b[i] = a[i] | mask;
			}
			sort(all(b));
			bool w = true;
			rep(i,0,n-1){
				if (b[i] == b[i+1]){
					w = false;
					break;
				}
			}
			if (w){
				M = max(M, __builtin_popcount(mask));
			}
		}
		cout << (m - M) << endl;


		cin >> m >> n;
	}
}