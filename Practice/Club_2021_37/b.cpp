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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while(n--){
		int t;
		cin >> t;
		int x1,y1,x2,y2;
		rep(i,0,t){
			string s;
			cin >> s;
			rep(j,0,t){
				char a = s[j];
				// cin >> a;
				if (a=='*') {
					x2 = x1;
					y2 = y1;
					x1 = i;
					y1 = j;
				}
			}
		}
		if (x1 == x2) {
			x2 = (x1+1)%t;
		}
		if (y1==y2){
			y2 = (y1+1)%t;
		}
		rep(i,0,t){
			rep(j,0,t){
				if ( (i==x1 || i==x2) && (j==y1 || j==y2) ){
					cout <<'*';
				}else{
					cout <<'.';
				}
			}
			cout << endl;
		}
	}
}