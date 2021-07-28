#include <bits/stdc++.h>
using namespace std;
// done
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
		int n;
		cin >> n;
		vi a(2*n);
		rep(i,0,2*n){
			cin >> a[i];
		}
		sort(all(a));
		vi b(2*n);
		rep(i,0,n){
			b[2*i] = a[i];
			b[2*i+1] = a[i+n];
		}
		for(auto e:b) cout << e << " ";
			cout << endl;
	}
	
}