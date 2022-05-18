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
	rep(T, 1, t+1){
		int a, b, c, d;
		a=b=c=d=1e7;
		rep(i,0,3){
			int e,f,g,h;
			cin >> e >>f >>g >> h;
			a = min(a,e);
			b = min(b,f);
			c = min(c,g);
			d = min(d,h);
		}

		cout << "Case #" << T << ":";
		int tot = 1000000;
		if (a+b+c+d >= 1000000){
			cout << " "<< min(a, tot);
			tot-=min(a, tot);
			cout << " "<< min(b, tot);
			tot-=min(b, tot);
			cout<< " " << min(c, tot);
			tot-=min(c, tot);
			cout<< " " << min(d, tot);
			tot-=min(d, tot);
		} else {
			cout << " IMPOSSIBLE";
		}
		cout << endl;


	}
}