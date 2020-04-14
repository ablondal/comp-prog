#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

int R,C;


ll solve(){
	cin >> R >> C;
	vector <vi> S(C,vi(R)), l(C,vi(R,-1)), r(C,vi(R,-1)), u(C,vi(R,-1)), d(C,vi(R,-1));
	vector <vi> N(C,vi(R)), n(C,vi(R));
	// cout << 1 << endl;
	for(int j=0; j<R; ++j){
		for(int i=0; i<C; ++i){
			cin >> S[i][j];
			if(i!=0) l[i][j] = i-1;
			if(i!=C-1) r[i][j] = i+1;
			if(j!=0) u[i][j] = j-1;
			if(j!=R-1) d[i][j] = j+1;
		}
	}
	// cout << 2 << endl;
	bool deld = true;
	ll tot_int = 0;
	int n_rd = 0;

	while(deld){
		deld = false;
		n_rd++;
		// cout << "rd " << n_rd << endl;
		for(int i=0; i<C; ++i){
			for(int j=0; j<R; ++j){
				// cout << "0_" << endl;
				N[i][j] = 0;
				n[i][j] = 0;
				// cout << "1_" << endl;
				if (u[i][j]!=-1){
					N[i][j] += S[i][u[i][j]];
					n[i][j]++;
				}
				// cout << "2_" << endl;
				if (d[i][j]!=-1){
					N[i][j] += S[i][d[i][j]];
					n[i][j]++;
				}
				// cout << "3_" << endl;
				if (l[i][j]!=-1){
					N[i][j] += S[l[i][j]][j];
					n[i][j]++;
				}
				// cout << "4_" << endl;
				if (r[i][j]!=-1){
					// cout << "h" << endl;
					N[i][j] += S[r[i][j]][j];
					// cout << "e" << endl;
					n[i][j]++;
				}
				// cout << "l" << endl;
				tot_int += S[i][j];
				// cout << "p" << endl;
			}
		}
		// cout << "RDC@" << endl;
		for(int i=0; i<C; ++i){
			for(int j=0; j<R; ++j){
				if (S[i][j] && n[i][j]*S[i][j] < N[i][j]){
					deld = true;
					S[i][j] = 0;
					// cout << "1_" << endl;
					if (u[i][j]!=-1){
						d[i][u[i][j]] = d[i][j];
					}
					// cout << "2_" << endl;
					if (d[i][j]!=-1){
						u[i][d[i][j]] = u[i][j];
					}
					// cout << "3_" << endl;
					if (l[i][j]!=-1){
						r[l[i][j]][j] = r[i][j];
					}
					// cout << "4_" << endl;
					if (r[i][j]!=-1){
						l[r[i][j]][j] = l[i][j];
					}
				}
			}
		}
	}
	return tot_int;

}


int main(){
	int T;
	cin >> T;
	for(int t=1;t<=T;++t){
		ll a = solve();
		cout << "Case #" << t << ": " << a << endl;
		// solve();
	}
	return 0;
}



















