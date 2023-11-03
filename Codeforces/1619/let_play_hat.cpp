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
		int n, m, k;
		cin >> n >> m >> k;
		int b = n % m;
		int ptr = 0;
		while(k--){
			rep(i,0,b){
				cout << (n/m)+1;
				rep(j,0,(n/m)+1){
					cout << " " << ptr + 1;
					ptr = (ptr+1)%n;
				}
				cout << endl;
			}
			int ptr2 = ptr;
			rep(i,b,m){
				cout << (n/m);
				rep(j,0,(n/m)){
					cout << " " << ptr2 + 1;
					ptr2 = (ptr2+1)%n;
				}
				cout << endl;
			}
		}
		cout << endl;
	}
}