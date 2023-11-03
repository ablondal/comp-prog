#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int below(int a, int i){
	a--;
	int ct = 0;
	while(a > 0 && a & (1<<i)) {
		a--;
		ct++;
	}
	while(a > 0 && !(a & (1<<i))) {
		a--;
	}
	return ct + (a/2);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while(t--){
		int l, r;
		cin >> l >> r;
		r++;
		vi a(32, 0);
		
		rep(i,0,32){
			a[i] = below(r, i) - below(l, i);
		}

		int M = 0;
		rep(i,0,32){
			M = max(M, a[i]);
		}
		cout << r-l-M << endl;
	}
}