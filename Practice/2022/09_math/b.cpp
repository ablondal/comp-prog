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

double ch[15][15] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ch[0][0] = 1;
	
	int t;
	cin >> t;
	while(t--){
		ch[0][0] = 1;
		rep(i,1,15){
			ch[0][i] = 0;
		}
		int r, s, x, y, w;
		cin >> r >> s >> x >> y >> w;
		double p = (double)(s-r+1) / (double)s;
		// cout << p << endl;
		double tot = 0;
		rep(i,1,y+1){
			rep(j,0,x+1){
				if (j == x){
					tot += ch[i-1][j-1] * p;
				}else{
					ch[i][j] = ch[i-1][j] * (1-p) + ch[i-1][j-1] * p;
				}
			}
		}
		// cout << tot << endl;
		cout << (w * tot > 1 ? "yes" : "no")  << endl;

	}
}