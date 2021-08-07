#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1007;
const int MOD = 1000000007;

ll w_d[1007][1007];
ll w_u[1007][1007];
int c_d[1007][1007];
int c_u[1007][1007];
int c[1007][1007];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int q;
	cin >> n;
	rep(i,1,n+1){
		string a;
		cin >> a;
		rep(j,1,n+1){
			if (a[j-1]=='C') c[i][j]=1;
			else c[i][j] = 0;
		}
	}
	w_d[0][1] = 1;
	w_u[n][n+1] = 1;
	// c_d[0][0] = c[0][0];
	// c_u[n-1][n-1] = c[n-1][n-1];
	rep(i,1,n+1){
		rep(j,1,n+1){
			c_d[i][j] = c[i][j];
			if (c_d[i-1][j] == c_d[i][j-1]){
				w_d[i][j] = (w_d[i][j-1]+w_d[i-1][j]) % MOD;
			}else if(c_d[i-1][j] > c_d[i][j-1]){
				w_d[i][j] = w_d[i-1][j];
			}else{
				w_d[i][j] = w_d[i][j-1];
			}
			c_d[i][j] += max(c_d[i-1][j], c_d[i][j-1]);
		}
	}

	for(int i=n; i>0; --i){
		for(int j=n; j>0; --j){
			c_u[i][j] = c[i][j];
			if (c_u[i+1][j] == c_u[i][j+1]){
				w_u[i][j] = (w_u[i][j+1]+w_u[i+1][j]) % MOD;
			}else if(c_u[i+1][j] > c_u[i][j+1]){
				w_u[i][j] = w_u[i+1][j];
			}else{
				w_u[i][j] = w_u[i][j+1];
			}
			c_u[i][j] += max(c_u[i+1][j], c_u[i][j+1]);
		}
	}

	cin >> q;

	rep(i,0,q){
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		y1+=1;
		y2+=1;
		x1+=1;
		x2+=1;
		int max_c = 0;
		ll ways = 0;
		int d = 1;
		while( (y2+d<n+1 && x1-d>0) || (y1-d>0 && x2+d<n+1) ){
			int i1 = y2+d;
			int j1 = x1-d;
			// printf("%d %d\n", i1, j1);
			if (i1<n+1 && j1>0){
				int c1 = c_u[i1][j1] + c_d[i1][j1] - c[i1][j1];
				if (c1 > max_c){
					max_c = c1;
					ways = ((ll)w_u[i1][j1] * (ll)w_d[i1][j1]) % MOD;
				}else if(c1 == max_c){
					ways += ((ll)w_u[i1][j1] * (ll)w_d[i1][j1]) % MOD;
					ways = ways % MOD;
				}
			}
		// cout << max_c << " " << ways << endl;
			i1 = y1-d;
			j1 = x2+d;
						// printf("%d %d\n", i1, j1);

			if (i1>0 && j1<n+1){
				int c1 = c_u[i1][j1] + c_d[i1][j1] - c[i1][j1];
				if (c1 > max_c){
					max_c = c1;
					ways = ((ll)w_u[i1][j1] * (ll)w_d[i1][j1]) % MOD;
				}else if(c1 == max_c){
					ways += ((ll)w_u[i1][j1] * (ll)w_d[i1][j1]) % MOD;
					ways = ways % MOD;
				}
			}
					// cout << max_c << " " << ways << endl;

			d++;
		}
		cout << max_c << " " << ways << endl;
	}

	// cout << 
}