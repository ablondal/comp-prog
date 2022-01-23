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
const ll M = 1e9+87;

double nn;
double DP[307][307][307] = {{{0}}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	nn = n;
	int c0=0,c1=0,c2=0,c3=0;
	rep(i,0,int(n)){
		int a;
		cin >> a;
		if (a==0) c0++;
		if (a==1) c1++;
		if (a==2) c2++;
		if (a==3) c3++;
	}
	int a=c0, b=c1, c=c2;
	DP[n][0][0] = 0;
	for(c0=n-1; c0>=0; c0--){
		for(c1=n-c0; c1>=0; c1--){
			for(c2=n-c1-c0; c2>=0; c2--){
				c3 = n-c1-c0-c2;
				{
					DP[c0][c1][c2] = (c0/(nn-c0));
					if (c1) {
						DP[c0][c1][c2] +=
							(c1/(nn-c0)) * (DP[c0+1][c1-1][c2] + 1);
					}
					if (c2) {
						DP[c0][c1][c2] +=
							(c2/(nn-c0)) * (DP[c0][c1+1][c2-1] + 1);
					}
					if (c3) {
						DP[c0][c1][c2] +=
							(c3/(nn-c0)) * (DP[c0][c1][c2+1] + 1);
					}
					// printf("DP[%d][%d][%d][%d] = %lf\n", c0, c1, c2, c3, DP[c0][c1][c2][c3]);
				}
			}
		}
	}
	cout << setprecision(18) << DP[a][b][c] << endl;
}